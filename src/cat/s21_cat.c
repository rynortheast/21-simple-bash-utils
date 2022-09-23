#include "s21_cat.h"

int main(int argc, char **argv) {
  if (argc > 1) {
    ops options = {0};
    int file_idx = parse_ops(argc, argv, &options);
    while (file_idx < argc) {
      FILE *file;
      file = fopen(argv[file_idx], "r");
      if (NULL == file) {
        fprintf(stderr, "s21_cat: %s: No such file or directory\n",
                argv[file_idx]);
      } else {
        s21_cat(file, options);
      }
      file_idx++;
    }
  }
  return 0;
}

int parse_ops(int argc, char **str, ops *options) {
  int offset = 1;
  while (offset < argc - 1 && str[offset][0] == '-') {
    if (!strcmp(str[offset], "--number-nonblank") ||
        (!strcmp(str[offset], "-b")))
      options->b = 1;
    if (!strcmp(str[offset], "-e")) {
      options->e = 1;
      options->v = 1;
    }
    if (!strcmp(str[offset], "-E")) options->e = 1;
    if (!strcmp(str[offset], "-n") || !strcmp(str[offset], "--number"))
      options->n = 1;
    if (!strcmp(str[offset], "-s") || !strcmp(str[offset], "--squeeze-blank"))
      options->s = 1;
    if (!strcmp(str[offset], "-t")) {
      options->t = 1;
      options->v = 1;
    }
    if (!strcmp(str[offset], "-T")) options->t = 1;
    if (!strcmp(str[offset], "-v")) options->v = 1;
    offset++;
  }
  if (options->b && options->n) {
    options->n = 0;
  }
  return offset;
}

void s21_cat(FILE *file, ops options) {
  char sym = '0';
  while ((sym = getc(file)) != EOF) {
    char *str = (char *)calloc(SIZE, 1);
    if (str) {
      int idx = 0;
      while (sym != EOF && sym != '\n' && str) {
        str[idx] = sym;
        idx++;
        sym = getc(file);
        if (idx % SIZE == 0 && idx > 0) {
          str = (char *)check_real(str, idx + SIZE);
        }
      }
      if (sym == EOF) {
        options.eof = 1;
      }
      if (idx == 0) {
        options.empty++;
      } else {
        options.empty = 0;
      }
      str = (char *)check_real(str, idx + 1);
      if (str) {
        str[idx] = '\n';
        if (!(options.b && options.empty) &&
            (!options.s || options.empty <= 1)) {
          options.cnt++;
        }
        print(str, options);
      }
      free(str);
    }
  }
}

void print(char *line, ops options) {
  if (options.empty < 2 || !options.s) {
    if (options.n || (options.b && line[0] != '\n')) {
      printf("%6d\t", options.cnt);
    }
    for (int i = 0; line[i] != '\n'; i++) {
      if (options.v) {
        if (line[i] >= 0 && line[i] <= 31 && line[i] != 9) {
          printf("^%c", 64 + line[i]);
          continue;
        } else if (line[i] == 127) {
          printf("^?");
          continue;
        } else if (line[i] < -96) {
          printf("M-^%c", line[i] - 64);
          continue;
        }
      }
      if (options.t && line[i] == 9) {
        printf("^I");
      } else {
        printf("%c", line[i]);
      }
    }
    if (!options.eof) {
      if (options.e)
        printf("$\n");
      else
        printf("\n");
    }
  }
}

void *check_real(void *ptr, size_t size) {
  void *tmp;
  tmp = realloc(ptr, size);
  if (!tmp && ptr) free(ptr);
  return (tmp);
}
