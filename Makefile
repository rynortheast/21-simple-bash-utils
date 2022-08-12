
CAT_DIR = ./cat
GREP_DIR = ./grep

CAT_FILES = $(CAT_DIR)/s21_cat.c
GREP_FILES = $(GREP_DIR)/s21_grep.c

FLAGS = -Wall -Wextra -Werror -std=c11 -pedantic

all: s21_cat s21_grep

s21_cat: Makefile $(CAT_FILES)
	gcc $(FLAGS) $(CAT_FILES) -o s21_cat

s21_grep: Makefile $(GREP_FILES)
	gcc $(FLAGS) $(GREP_FILES) -o s21_grep

rebuild:
	make clean
	make all

clean:
	rm -f s21_cat s21_grep
