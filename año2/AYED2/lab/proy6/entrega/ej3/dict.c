#include "dict.h"
#include "key_value.h"
#include "string.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _node_t {
  dict_t left;
  dict_t right;
  key_t key;
  value_t value;
};

bool is_empty_dict(dict_t dict)
{
  return dict == NULL;
}

static struct _node_t* new_node(key_t key, value_t value)
{
  struct _node_t* node = malloc(sizeof(struct _node_t));
  node->key = key;
  node->value = value;
  node->left = dict_empty();
  node->right = dict_empty();
  return node;
}

static bool invrep(dict_t d)
{
  return (is_empty_dict(d)) || (is_empty_dict(d->left) && is_empty_dict(d->right)) //
      || (is_empty_dict(d->left) || key_less(d->left->key, d->key))		   //
      && (is_empty_dict(d->right) || key_less(d->key, d->right->key))		   //
      && invrep(d->right)							   //
      && invrep(d->left);							   //
}

dict_t dict_empty(void)
{
  dict_t dict = NULL;
  return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def)
{
  assert(invrep(dict));

  if (is_empty_dict(dict)) {
    dict = new_node(word, def);
  } else if (key_less(word, dict->key)) {
    dict->left = dict_add(dict->left, word, def);
  } else if (key_less(dict->key, word)) {
    dict->right = dict_add(dict->right, word, def);
  } else {
    value_t tmp = dict->value;
    dict->value = def;
    value_destroy(tmp);
  }

  bool res1 = dict_exists(dict, word);
  assert(invrep(dict) && res1);
  return dict;
}

value_t dict_search(dict_t dict, key_t word)
{
  assert(invrep(dict));
  key_t def = NULL;

  if (!is_empty_dict(dict)) {
    if (key_eq(dict->key, word)) {
      def = dict->value;
    } else {
      if (key_less(dict->key, word)) {
	def = dict_search(dict->right, word);
      } else if (key_less(word, dict->key)) {
	def = dict_search(dict->left, word);
      }
    }
  }

  return def;
}

bool dict_exists(dict_t dict, key_t word)
{
  bool exists = false;

  assert(invrep(dict));

  if (is_empty_dict(dict)) {
    return exists;
  } else if (key_less(dict->key, word)) {
    exists = dict_exists(dict->right, word);
  } else if (key_less(word, dict->key)) {
    exists = dict_exists(dict->left, word);
  } else {
    exists = key_eq(dict->key, word);
  }

  return exists;
}

unsigned int dict_length(dict_t dict)
{
  unsigned int length = 0;
  assert(invrep(dict));

  if (!is_empty_dict(dict)) {
    length = 1 + dict_length(dict->left) + dict_length(dict->right);
  }

  assert(invrep(dict) && (is_empty_dict(dict) || length > 0));
  return length;
}

key_t dict_get_min(dict_t dict)
{
  key_t min_k;
  assert(invrep(dict));

  struct _node_t* p = dict;
  while (!is_empty_dict(p->left)) {
    p = p->left;
  }
  min_k = p->key;

  assert(invrep(dict) && dict_exists(dict, min_k));
  return min_k;
}

dict_t dict_remove(dict_t dict, key_t word)
{
  assert(invrep(dict));
  dict_t r = dict;

  if (!is_empty_dict(dict)) {

    if (key_less(word, dict->key)) {
      dict->left = dict_remove(dict->left, word);
    }

    else if (key_less(dict->key, word)) {
      dict->right = dict_remove(dict->right, word);
    }

    else {
      if (is_empty_dict(dict->left)) {
	r = dict->right;
	dict->key = string_destroy(dict->key);
	dict->value = string_destroy(dict->value);
	free(dict);
	dict = NULL;
      } else if (is_empty_dict(dict->right)) {
	r = dict->left;
	dict->key = string_destroy(dict->key);
	dict->value = string_destroy(dict->value);
	free(dict);
	dict = NULL;
      } else {
	key_t temp_key = dict_get_min(dict->right);
	value_t temp_value = dict_search(dict->right, temp_key);
	dict->key = temp_key;
	dict->value = temp_value;
	dict->right = dict_remove(dict->right, temp_key);
	r = dict;
      }
    }
  }
  assert(invrep(r) && !dict_exists(r, word));
  return r;
}

dict_t dict_remove_all(dict_t dict)
{
  assert(invrep(dict));
  if (!is_empty_dict(dict)) {
    dict_remove_all(dict->left);
    dict_remove_all(dict->right);
    key_destroy(dict->key);
    value_destroy(dict->value);
    free(dict);
    dict = dict_empty();
  }
  assert(is_empty_dict(dict));
  return dict;
}

void dict_dump(dict_t dict, FILE* file)
{
  assert(invrep(dict));
  if (!is_empty_dict(dict)) {
    dict_dump(dict->left, file);
    key_dump(dict->key, file);
    fprintf(file, ":");
    value_dump(dict->value, file);
    fprintf(file, "\n");
    fflush(file);
    dict_dump(dict->right, file);
  }
}

dict_t dict_destroy(dict_t dict)
{
  return dict_remove_all(dict);
}
