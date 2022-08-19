
# S21_BashUtils

<div align="center">PREVIEW_WILL_BE_ADDED_LATER.png</div>

## Table of contents
* [About](#about)
* [Goal & requirements](#goal--requirements)
* [Key learnings](#key-learnings)
* [Building](#building)
* [Overview of implemented code](#overview-of-implemented-code)
* [Credits](#credits)

## About 

Implement some basic Bash utilities to work with texts from files using C language.

## Goal & requirements 

. . .

## Key learnings

. . .

## Overview of implemented code

### cat Usage

COMMAND: `cat [OPTION] [FILE]...` | ✅ |

### cat Options

| No. | Options | Description | Status |
| ------ | ------ | ------ | ------ |
| 1 | -b (GNU: --number-nonblank) | numbers only non-empty lines | 🔲 |
| 2 | -e implies -v (GNU only: -E the same, but without implying -v) | but also display end-of-line characters as $  | 🔲 |
| 3 | -n (GNU: --number) | number all output lines | 🔲 |
| 4 | -s (GNU: --squeeze-blank) | squeeze multiple adjacent blank lines | 🔲 |
| 5 | -t implies -v (GNU: -T the same, but without implying -v) | but also display tabs as ^I  | 🔲 |

### grep Usage

COMMAND: `grep [options] template [file_name]` | 🔲 |

### grep Options

| No. | Options | Description | Status |
| ------ | ------ | ------ | ------ |
| 1 | -e | pattern | 🔲 |
| 2 | -i | Ignore uppercase vs. lowercase.  | 🔲 |
| 3 | -v | Invert match. | 🔲 |
| 4 | -c | Output count of matching lines only. | 🔲 |
| 5 | -l | Output matching files only.  |
| 6 | -n | Precede each matching line with a line number. | 🔲 |
| 7 | -h | Output matching lines without preceding them by file names. | 🔲 |
| 8 | -s | Suppress error messages about nonexistent or unreadable files. | 🔲 |
| 9 | -f file | Take regexes from a file. | 🔲 |
| 10 | -o | Output the matched parts of a matching line. | 🔲 |

## Building

1. Clone this repository via
    - SSH `git@github.com:rynortheast/S21_BashUtils.git` or
    - HTTPS `https://github.com/rynortheast/S21_BashUtils.git`
2. Change code base if necessary
3. Run `. . .` to build project and . . .

## Credits

- Developer: [RV-304 (@rynortheast)](https://github.com/rynortheast)
- 21-SCHOOL for providing this task as a part of our curriculum ✌️🔥
