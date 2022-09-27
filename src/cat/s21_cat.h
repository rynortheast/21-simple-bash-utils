#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_01 "s21_cat: %s: No such file or directory\n"

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int nth;
  int isEOF;
  int countEmptyLine;
} options;

void setupConfig(options *config, int length, char symbol);
int scanOptions(int argc, char **argv, options *config);
void *increaseLengthLine(char *line, int size);
void printLine(char *line, options options);
void s21_cat(FILE *file, options config);

#endif  // SRC_CAT_S21_CAT_H_
