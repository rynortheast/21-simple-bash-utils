#!python3

from itertools import combinations_with_replacement
from random import shuffle
from os import system

falshivka = "./s21_cat"
original = "cat"

file_name = 'TEST-FILE'
file_format = ".testing"

suite = [
    'TEST-SUITE/TEST-FILE_002'
]

flags = {
    '-b',
    '-e',
    '-n',
    '-s',
    '-v',
    '-t'
}

all_var = list(combinations_with_replacement(flags, len(flags)))

def file_comparison(a, b):
    with open(a) as file_1:
        with open(b) as file_2:
            a, b = file_1.read(), file_2.read()
            if a != b:

                count = 0
                for i in range(len(a)):
                    if a[i] == '\n':
                        count += 1
                    if len(b) == i:
                        break
                    if a[i] != b[i]:
                        break

                print("===============A===============")
                print(a[max(0, i-50):min(len(a), i+50)])
                print("===============B===============")
                print(b[max(0, i-50):min(len(b), i+50)])
                print("===============================")
                print("Line:", count, " char:", i)
                input("Press any key to continue:\n")

            else:
                print("\033[42m\033[1m YES \033[0m")


for test in range(len(all_var)):
    cur_flags_ = all_var[test]
    for cur_flags in (cur_flags_, set(cur_flags_)):
        shuffle(suite)
        print(f"Current TEST [{test + 1} / {len(all_var)}] - ", end='')
        for i, func in (('0', falshivka), ('1', original)):
            m_str = f'{func} {" ".join(cur_flags)} {" ".join(suite)} > {file_name+"-"+i+file_format}'
            system("echo '{}' >> commands.testing".format(m_str));
            system(m_str)
        file_comparison(file_name+'-0'+file_format,
                        file_name+'-1'+file_format)

system('rm -rf *' + file_format)
