# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 15:03:02 by lumaret           #+#    #+#              #
#    Updated: 2024/03/18 15:03:50 by lumaret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Création du fichier input.txt avec des données pour le test
echo -e "d\nc\na\nb" > input.txt

# Exécution de la première commande avec pipex
./pipex input.txt "cat" "sort" output.txt

# Exécution de la commande shell équivalente et stockage du résultat dans un fichier temporaire
cat input.txt | sort > expected_output.txt

# Comparaison des résultats
if diff -q output.txt expected_output.txt > /dev/null; then
    echo -e "\033[32m[OK]\033[0m"
else
    echo -e "\033[31m[FAIL]\033[0m"
fi


echo -e "file1.txt\nfile2.txt\nfile3.txt" > input

# Exécution de la deuxième commande avec pipex
./pipex input "ls -l" "grep .txt" output.txt

# Exécution de la commande shell équivalente et stockage du résultat dans un fichier temporaire
ls -l input | grep .txt > expected_output2.txt

# Comparaison des résultats
if diff -q output.txt expected_output2.txt > /dev/null; then
    echo -e "\033[32m[OK]\033[0m"
else
    echo -e "\033[31m[FAIL]\033[0m"
fi

# Nettoyage des fichiers temporaires
rm input.txt output.txt expected_output.txt expected_output2.txt input