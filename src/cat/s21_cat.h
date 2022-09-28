#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_01 "s21_cat: %s: No such file or directory\n"
#define ERROR_02 "s21_cat: invalid option -- '%c'\n"

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int newLine;
  int counterB;
  int counterS;
  int emptyLine;
  int numberFiles;
} options;

void s21_cat_programm(int argc, char **argv);

int scanOptions(int argc, char **argv, options *config);
FILE *printData(FILE *file, options *config);

#endif  // SRC_CAT_S21_CAT_H_
