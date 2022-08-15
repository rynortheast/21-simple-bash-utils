#include "s21_cat.h"

int main(int argc, char ** argv) {
    s21_cat(argc, argv);
    return EXIT_SUCCESS;
}

void s21_cat(int argc, char ** argv) {

    // printf("TEST: |%d| - |%s| - |%s|", argc, argv[0], argv[1]);

    if (argc >= 2) {

        options config = {0, 0, 0, 0, 0};

        int indexStartFiles = scanOptionsCommand(argc, argv, &config);

        // printf("TEST : %d : %d%d%d%d%d", indexStartFiles, config.b, config.e, config.n, config.s, config.t);

        outputDataFiles(indexStartFiles, argc, argv, config);
    }
}

void outputDataFiles(int indexStartFiles, int argc, char ** argv, options config) {
    for (int y = indexStartFiles; y < argc; y += 1) {
        FILE * file = fopen(argv[y], "r");
        readFile(file, config);
        fclose(file);
    }
}

void readFile(FILE * file, options config) {
    char symbol = '0';
    while (fscanf(file, "%c", &symbol) != EOF)
        printf("%c", symbol);
}

int scanOptionsCommand(int argc, char ** argv, options * config) {
    int indexStartFiles = argc;
    for (int y = 1; y < argc; y += 1) {
        if (argv[y][0] == '-') {
            if (scanLongOptions(y, argv, config) == 0)
                scanShortOptions(y, argv, config);
        } else {
            indexStartFiles = y;
            break;
        }
    }
    return indexStartFiles;
}

int scanLongOptions(int y, char ** argv, options * config) {
    int status = 1;
    if (strcmp(argv[y], "--number") == 0) config -> n = 1;
    else if (strcmp(argv[y], "--squeeze-blank") == 0) config -> s = 1;
    else if (strcmp(argv[y], "--number-nonblank") == 0) config -> b = 1;
    else status = 0;
    return status;
}

void scanShortOptions(int y, char ** argv, options * config) {
    for (size_t x = 1; x < strlen(argv[y]); x += 1) {
        if (argv[y][x] == 'b')config -> b = 1;
        else if (argv[y][x] == 'n') config -> n = 1;
        else if (argv[y][x] == 's') config -> s = 1;
        else if (strchr("eE", argv[y][x])) config -> e = 1;
        else if (strchr("tT", argv[y][x])) config -> t = 1;
    }
}
