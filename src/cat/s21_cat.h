#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int b;
    int e;
    int n;
    int s;
    int t;
} options;

void s21_cat(int argc, char ** argv);
void readFile(FILE * file, options config);
int scanLongOptions(int y, char ** argv, options * config);
void scanShortOptions(int y, char ** argv, options * config);
int scanOptionsCommand(int argc, char ** argv, options * config);
void outputDataFiles(int indexStartFiles, int argc, char ** argv, options config);

#endif  // SRC_CAT_S21_CAT_H_