#!/bin/bash

TEMPLATE_FILE="./TEST_FILES/TEMPLATE_001"
TEST_FILE="./TEST_FILES/SUITE_001"
TEMPLATE="[0-9]"

grep -e ${TEMPLATE} -e ${TEMPLATE_FILE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -e ${TEMPLATE} -e ${TEMPLATE_FILE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -f ${TEMPLATE_FILE} -e ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -f ${TEMPLATE_FILE} -e ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -f ${TEMPLATE_FILE} s21_grep.c s21_grep.h > ORIGINAL.txt && ./s21_grep -f ${TEMPLATE_FILE} s21_grep.c s21_grep.h > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -vf ${TEMPLATE_FILE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -vf ${TEMPLATE_FILE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -cf ${TEMPLATE_FILE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -cf ${TEMPLATE_FILE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -lf ${TEMPLATE_FILE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -lf ${TEMPLATE_FILE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -nf ${TEMPLATE_FILE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -nf ${TEMPLATE_FILE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -hf ${TEMPLATE_FILE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -hf ${TEMPLATE_FILE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -h if ${TEST_FILE} s21_grep.h > ORIGINAL.txt && ./s21_grep -h if ${TEST_FILE} s21_grep.h > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt	
grep -ie ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -ie ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -ve ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -ve ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -ce ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -ce ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -le ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -le ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -ne ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -ne ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -he ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -he ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -se ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -se ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -oe ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -oe ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -iv ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -iv ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -ic ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -ic ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -il ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -il ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -in ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -in ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -ih ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -ih ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -is ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -is ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -io ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -io ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -vc ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -vc ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -vl ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -vl ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -vn ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -vn ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -vh ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -vh ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -vs ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -vs ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -vo ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -vo ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -cl ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -cl ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -cn ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -cn ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -ch ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -ch ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -cs ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -cs ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -co ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -co ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -ln ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -ln ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -lh ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -lh ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -ls ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -ls ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -lo ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -lo ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -nh ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -nh ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -ns ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -ns ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -no ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -no ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -hs ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -hs ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -ho ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -ho ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -l ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -l ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -v ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -v ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -c ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -c ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -n ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -n ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -o ${TEMPLATE} ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -o ${TEMPLATE} ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep "[0-9]" ${TEST_FILE} > ORIGINAL.txt && ./s21_grep "[0-9]" ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt
grep -i RY ${TEST_FILE} > ORIGINAL.txt && ./s21_grep -i RY ${TEST_FILE} > FAKE.txt && diff -s ORIGINAL.txt FAKE.txt

rm -f ORIGINAL.txt FAKE.txt
