#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

#define ERROR_01 "s21_cat: %s: No such file or directory\n"

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int nth;
  int countEmptyLine;
  int new_line;
  int isEOF;
} options;

int scanOptions(int argc, char **argv, options *config);
void *increaseLengthLine(char *line, int size);
void setupConfig(options *config, int length, char symbol);
void s21_cat(FILE *file, options config);
void printLine(char *line, options options);

#endif  // SRC_CAT_S21_CAT_H_
