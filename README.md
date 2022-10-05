
# 21-simple-bash-utils

<div align="center">PREVIEW_WILL_BE_ADDED_LATER.png</div>

***

Educational project SimpleBashUtils from organization «School 21».  
  
Development of Bash text utilities cat & grep in C programming languages. Developed functions have all the original flags supported, including paired combinations.

<details>
<summary>[ SPOILER ] Overview of implemented code</summary>

### s21_cat
  
TEMPLATE: `cat [OPTION] [FILE]`
  
| No. | Option | Description | Status |
| ------ | ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | numbers only non-empty lines | ✅ |
| 2 | -e подразумевает -v (только GNU: -E то же самое, но без -v) | but also display end-of-line characters as $ | ✅ |
| 3 | -n (GNU: --number) | number all output lines | ✅ |
| 4 | -s (GNU: --squeeze-blank) | squeeze multiple adjacent blank lines | ✅ |
| 5 | -t подразумевает -v (GNU: -T то же самое, но без -v) | but also display tabs as ^I | ✅ |

### s21_grep
  
TEMPLATE: `grep [OPTION] [TEMPLATE] [FILE]`
  
| No. | Option | Description | Status |
| ------ | ------ | ------ | ------ |
| 1 | -e | pattern | ✅ |
| 2 | -i | ignore uppercase vs. lowercase | ✅ |
| 3 | -v | invert match | ✅ |
| 4 | -c | output count of matching lines only. | ✅ |
| 5 | -l | output matching files only | ✅ |
| 6 | -n | precede each matching line with a line number | ✅ |
| 7 | -h | output matching lines without preceding them by file names | ✅ |
| 8 | -s | suppress error messages about nonexistent or unreadable files | ✅ |
| 9 | -f file | take regexes from a file | ✅ |
| 10 | -o | output the matched parts of a matching line | ✅ |

</details>

— Thanks to 21-SCHOOL for provided assignment and special learning conditions ✌️🔥

## Usage

1. Clone this repository via
    - SSH `git@github.com:rynortheast/S21_string.git` or
    - HTTPS `https://github.com/rynortheast/S21_string.git`
2. Change code base if necessary
3. Working with s21_cat:
    - Run `make s21_cat` to build programm
    - Run `python TEST.py` to run main tests
4. Working with s21_grep:
    - Run `make s21_grep` to build programm
    - Run `bash TEST.sh` to run main tests
