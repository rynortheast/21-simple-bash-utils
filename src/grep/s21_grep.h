#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_01 "s21_grep: %s: No such file or directory\n"

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int countFiles;
  int numberLine;
  int countMatches;
} options;

void s21_grep_programm(int argc, char **argv);

int scanOptions(int argc, char **argv, options *config, char **template);
void printMainData(char *str, options *options, char *tmpl, char *name);
void setConfigF(options *config, char **template, char *optarg);
void setConfigE(options *config, char **template, char *optarg);
void printfConfigO(regex_t my_regex, char *str, options config);
void s21_grep(char *name, options config, char *tmpl);
void printfAuxData(options config, char *path);
void *increaseLengthStr(void *str, int size);
int createTemplate(char **str, char *optarg);
void setupConfig(options *config, int argc);
void addTemplate(char **str, char *optarg);

#endif  // SRC_GREP_S21_GREP_H_
