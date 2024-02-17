/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);

    /*dumping the tree*/
    abb_dump(tree);


    if (!abb_is_empty(tree)) {
        printf("\n");
        printf("raiz: %d\n", abb_root(tree));
        printf("minimo: %d\n", abb_min(tree));
        printf("maximo: %d\n", abb_max(tree));
                                                
    } else {
        printf("\nÁrbol vacío\n");
    }

    tree = abb_destroy(tree);

    abb programtree = abb_empty();

    bool run=true;
    int op;

    while(run){
        printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
        printf("1 ........ Mostrar árbol por pantalla\n");
        printf("2 ........ Agregar un elemento\n");
        printf("3 ........ Eliminar un elemento\n");
        printf("4 ........ Chequear existencia de elemento\n");
        printf("5 ........ Mostrar longitud del árbol\n");
        printf("6 ........ Mostrar raiz, máximo y mínimo del árbol\n");
        printf("7 ........ Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &op);
        int elem;
        switch(op)
        {
        case 1:
            printf("\n");
            abb_dump(programtree);
            printf("\n");
            break;

        case 2:
            printf("Ingrese el elemento que quiere agregar: ");
            scanf("%d", &elem);
            programtree = abb_add(programtree, elem);
            break;

        case 3:
            printf("Ingrese el elemento que quiere eliminar: ");
            scanf("%d", &elem);
            programtree = abb_remove(programtree, elem);
            break;

        case 4:
            printf("Ingrese el elemento que quiere comprobar: ");
            scanf("%d", &elem);
            if(abb_exists(programtree, elem)){
                printf("Si existe \n");
            }else{
                printf("No existe \n");
            }
            break;

        case 5:
            printf("La longitud del arbol es de: %d \n", abb_length(programtree));
            break;

        case 6:
            printf("Raiz: %d \nMáximo: %d \nMínimo: %d \n",abb_root(programtree), abb_max(programtree), abb_min(programtree));
            break;

        case 7:
            run = false;
            programtree = abb_destroy(programtree);
            break;

        default:
            printf("Error! opcion invalida");
        }
    }

    return (EXIT_SUCCESS);
}
