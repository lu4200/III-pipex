#!/bin/bash
make > /dev/null 2>&1
####################################### CAT SORT ############################### 1

echo -e "d\nc\na\nb" > input.txt

./pipex input.txt "cat" "sort" output.txt

cat input.txt | sort > expected_output.txt

if diff -q output.txt expected_output.txt > /dev/null; then
    echo -e "\ncat + sort : \033[32m[OK]\033[0m \n"
else
    echo -e "\ncat + sort : \033[31m[FAIL]\033[0m \n"
fi

rm input.txt output.txt expected_output.txt

################################### DIRECTORY ################################## 2

echo -e "file1.txt\nfile2.txt\nfile3.txt" > input2.txt

./pipex . "ls -l" "grep .c" output2.txt

ls -l . | grep .c > test_output2.txt

if diff -q output2.txt test_output2.txt > /dev/null; then
    echo -e "Current Directory : \033[32m[OK]\033[0m \n"
else
    echo -e "Current Directory : \033[34m[CHECK LOGS]\033[0m \n"
fi

rm input2.txt output2.txt test_output2.txt

################################ GREP SORT ##################################### 3

echo -e "pomme\nbanane\nananas\nabricot" > input3.txt

./pipex input3.txt "grep an" "sort -r" output3.txt

grep an input3.txt | sort -r > expected_output3.txt

if diff -q output3.txt expected_output3.txt > /dev/null; then
    echo -e "grep + sort -r : \033[32m[OK]\033[0m \n"
else
    echo -e "grep + sort -r : \033[31m[FAIL]\033[0m \n"
fi

rm input3.txt output3.txt expected_output3.txt

############################## WC-W SORT-N ##################################### 4

echo -e "un mot\ndeux mots\nquatre mots ici" > input4.txt

./pipex input4.txt "wc" "sort -n" output4.txt

wc input4.txt | sort -n > expected_output4.txt

if diff -q output4.txt expected_output4.txt > /dev/null; then
    echo -e "wc + sort -n : \033[32m[OK]\033[0m \n"
else
    echo -e "wc + sort -n : \033[34m[CHECK LOGS]\033[0m \n"
fi

rm input4.txt output4.txt expected_output4.txt

############################# SED TRUNC ############################################ 5

echo -e "Ceci est une ligne\nEt une autre ligne\nEt encore une" > input5.txt

./pipex input5.txt "sed s/ligne/texte/" "tr a-z A-Z" output5.txt

sed 's/ligne/texte/' input5.txt | tr a-z A-Z > expected_output5.txt

if diff -q output5.txt expected_output5.txt > /dev/null; then
    echo -e "sed + trunc : \033[32m[OK]\033[0m \n"
else
    echo -e "sed + trunc : \033[31m[FAIL]\033[0m \n"
fi

rm input5.txt output5.txt expected_output5.txt

#################################### AWK SORT ########################################### 6

echo -e "pomme 1\nbanane 2\nananas 3" > input6.txt

./pipex input6.txt "awk {print\$2,\$1}" "sort -k1" output6.txt

awk '{print $2, $1}' input6.txt | sort -k1 > expected_output6.txt

if diff -q output6.txt expected_output6.txt > /dev/null; then
    echo -e "awk + sort : \033[32m[OK]\033[0m \n"
else
    echo -e "awk + sort : \033[31m[FAIL]\033[0m \n"
fi

rm input6.txt output6.txt expected_output6.txt

###################################### CUT UNIQ ####################################### 7

echo -e "a:x:1000:a\nb:x:1001:b\nc:x:1002:a" > input7.txt


./pipex input7.txt "cut -d : -f3" "uniq" output7.txt


cut -d ':' -f3 input7.txt | uniq > expected_output7.txt


if diff -q output7.txt expected_output7.txt > /dev/null; then
    echo -e "cut + uniq : \033[32m[OK]\033[0m \n"
else
    echo -e "cut + uniq : \033[31m[FAIL]\033[0m \n"
fi

rm input7.txt output7.txt expected_output7.txt

####################################### HEAD TAIL #################################### 8

seq 100 > input8.txt


./pipex input8.txt "head -n 10" "tail -n 5" output8.txt


head -n 10 input8.txt | tail -n 5 > expected_output8.txt


if diff -q output8.txt expected_output8.txt > /dev/null; then
    echo -e "head + tail : \033[32m[OK]\033[0m \n"
else
    echo -e "head + tail : \033[31m[FAIL]\033[0m \n"
fi

rm input8.txt output8.txt expected_output8.txt

######################################################################################### 9

make clean > /dev/null 2>&1