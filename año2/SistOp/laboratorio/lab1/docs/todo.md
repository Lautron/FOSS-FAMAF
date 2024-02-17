# Command
- [x] `scommand scommand_new(void);`
- [x] `scommand scommand_destroy(scommand self);`
- [x] `void scommand_pop_front(scommand self);`
- [x] `bool scommand_is_empty(const scommand self);`
- [x] `unsigned int scommand_length(const scommand self);`
- [x] `pipeline pipeline_new(void);`
- [x] `pipeline pipeline_destroy(pipeline self);`
- [x] `void pipeline_push_back(pipeline self, scommand sc);`
- [x] `void pipeline_pop_front(pipeline self);`
- [x] `void pipeline_set_wait(pipeline self, const bool w);`
- [x] `bool pipeline_is_empty(const pipeline self);`
- [x] `unsigned int pipeline_length(const pipeline self);`
- [x] `scommand pipeline_front(const pipeline self);`
- [x] `bool pipeline_get_wait(const pipeline self);`

# Builtin
- [ ] `bool builtin_is_internal(scommand cmd);`
- [ ] `bool builtin_alone(pipeline p);`
- [ ] `void builtin_run(scommand cmd);`

# Parsing
- [ ] `static scommand parse_scommand(Parser p);`
- [ ] `pipeline parse_pipeline(Parser parser);`

# Execute
- [ ] `void execute_pipeline(pipeline apipe);`

# Mybash
- [ ] `main(int argc, char *argv[]);`
