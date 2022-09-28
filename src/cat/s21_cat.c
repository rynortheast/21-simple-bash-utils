#include "s21_cat.h"

int main(int argc, char **argv) {
  s21_cat_programm(argc, argv);
  return 0;
}

//  TODO [s21_cat] Можно реализовать альтернативный
//  вариант функции для работы внутри другого кода.
void s21_cat_programm(int argc, char **argv) {
  if (argc > 1) {
    options config = {0};
    if (scanOptions(argc, argv, &config)) {
      for (int x = (argc - config.numberFiles); x < argc; x += 1) {
        FILE *file = fopen(argv[x], "r");
        if (file != NULL)
          fclose(printData(file, &config));
        else
          fprintf(stderr, ERROR_01, argv[x]);
      }
    }
  }
}

int scanOptions(int argc, char **argv, options *config) {
  int indexStartFiles = 1, status = 1, x = 1;

  for (; (x < argc && argv[x][0] == '-'); indexStartFiles = (x += 1)) {
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
    } else {
      fprintf(stderr, ERROR_02, argv[x][1]);
      status = 0;
    }
  }

  config->numberFiles = argc - indexStartFiles;

  return status;
}

//  TODO [printData] Необходим рефакторинг кода.
//  Нужно подумать как можно переписать условия,
//  чтоб это было более-менее читабельно.
FILE *printData(FILE *file, options *config) {
  for (char sym = '0'; (sym = getc(file)) != EOF;) {
    config->emptyLine = 0;
    if (config->s && config->counterS == 0 && sym == '\n') {
      config->counterS += 1;
    } else if (config->counterS != 0 && sym == '\n') {
      config->counterS += 1;
      config->emptyLine = 1;
    } else if (config->counterS > 1 && sym != '\n') {
      config->counterS = 0;
      config->e ? printf("$\n") : printf("\n");
      if (config->n != 0) printf("%6d\t", config->n++);
    } else {
      config->counterS = 0;
    }
    if (config->n != 0 || config->b != 0) {
      if (config->newLine == 1 && !(config->newLine = 0))
        printf("%6d\t", config->n++);
      if (config->n == 1) printf("%6d\t", config->n++);
      if (config->b == 1) printf("%6d\t", config->b++);
      if (sym == '\n' && config->n != 0 && config->emptyLine == 0)
        config->newLine = 1;
      if (sym == '\n' && config->b != 0) config->counterB += 1;
      if (sym != '\n' && config->counterB != 0 && config->counterS == 0)
        if (!(config->counterB = 0)) printf("%6d\t", config->b++);
    }
    if (sym == '\n' && config->e && config->emptyLine == 0) printf("$");
    if (config->v) {
      if (sym < 32 && sym != 9 && sym != 10)
        if (sym += 64) printf("^");
      if (sym == 127)
        if ((sym = '?')) printf("^");
    }
    if (config->t && sym == '\t')
      if ((sym = 'I')) printf("^");
    if (config->emptyLine == 0) printf("%c", sym);
  }
  return file;
}
