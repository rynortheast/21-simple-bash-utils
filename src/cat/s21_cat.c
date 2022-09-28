#include "s21_cat.h"

//  TODO [main] Необходимо реализацию s21_cat поместить в отдельную
//  фунцию, чтоб иметь альтернативные варианты использования.
//  Запускать отдельно или использовать внутри другого кода.
int main(int argc, char **argv) {
  if (argc > 1) {
    options config = {0};
    for (int x = scanOptions(argc, argv, &config); x < argc; x += 1) {
      FILE *file = fopen(argv[x], "r");
      if (file == NULL)
        fprintf(stderr, ERROR_01, argv[x]);
      else
        s21_cat(file, &config);
      fclose(file);
    }
  }
  return 0;
}

//  TODO [s21_cat] Необходим рефакторинг кода.
//  Не уверен, что правильно каждую интерацию выделять память.
void s21_cat(FILE *file, options *config) {
  for (char sym = '0'; (sym = getc(file)) != EOF;) {
    char *line = calloc(256, 1);
    int length = 0;

    for (line[length] = '\n'; sym != EOF && sym != '\n'; sym = getc(file)) {
      line[length] = sym;
      line[length += 1] = '\n';
      if (length % 256 == 0) line = increaseLengthLine(line, length + 256);
    }

    setupConfig(config, length, sym);
    printLine(line, config);
    free(line);
  }
}

int scanOptions(int argc, char **argv, options *config) {
  int indexStartFiles = 1, x = 1;
  for (; (x < argc - 1) && argv[x][0] == '-'; indexStartFiles = (x += 1)) {
    if (!strcmp(argv[x], "-b") || !strcmp(argv[x], "--number-nonblank")) {
      config->b = (config->n = 0) + 1;
    } else if (!strcmp(argv[x], "-s") || !strcmp(argv[x], "--squeeze-blank")) {
      config->s = 1;
    } else if (!strcmp(argv[x], "-n") || !strcmp(argv[x], "--number")) {
      config->n = config->b ? 0 : 1;
    } else if (!strcmp(argv[x], "-T")) {
      config->t = 1;
    } else if (!strcmp(argv[x], "-v")) {
      config->v = 1;
    } else if (!strcmp(argv[x], "-t")) {
      config->t = 1;
      config->v = 1;
    } else if (!strcmp(argv[x], "-e")) {
      config->e = 1;
      config->v = 1;
    } else if (!strcmp(argv[x], "-E")) {
      config->e = 1;
    }
  }
  return indexStartFiles;
}

//  TODO [printLine] Необходим рефакторинг кода.
void printLine(char *line, options *config) {
  if (config->countEmptyLine <= 1 || !config->s) {
    if (config->n || (config->b && line[0] != '\n'))
      printf("%6d\t", config->nth);
    for (int x = 0; line[x] != '\n'; x += 1) {
      if (config->v) {
        if (line[x] >= 0 && line[x] <= 31 && line[x] != 9) {
          printf("^%c", 64 + line[x]);
          continue;
        } else if (line[x] == 127) {
          printf("^?");
          continue;
        } else if (line[x] < -96) {
          printf("M-^%c", line[x] - 64);
          continue;
        }
      }
      if (config->t && line[x] == 9)
        printf("^I");
      else
        printf("%c", line[x]);
    }
    if (!config->isEOF) config->e ? printf("$\n") : printf("\n");
  }
}

void setupConfig(options *config, int length, char symbol) {
  config->isEOF = symbol == EOF ? 1 : 0;
  if (!(config->b && config->countEmptyLine))
    if (!config->s || config->countEmptyLine <= 1) config->nth += 1;
  config->countEmptyLine = length == 0 ? config->countEmptyLine + 1 : 0;
}

void *increaseLengthLine(char *line, int size) {
  char *aux = realloc(line, size);
  return aux;
}
