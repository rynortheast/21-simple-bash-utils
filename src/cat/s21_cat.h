#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

typedef struct ops {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int cnt;
  int empty;
  int new_line;
  int eof;
} ops;

void s21_cat(FILE *file, ops options);
void parse_file(char *name, ops options);
int parse_ops(int argc, char **str, ops *options);
void *check_real(void *ptr, size_t size);
void print(char *line, ops options);

#endif  // SRC_CAT_S21_CAT_H_
