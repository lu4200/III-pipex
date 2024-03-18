# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 15:03:02 by lumaret           #+#    #+#              #
#    Updated: 2024/03/18 18:47:48 by lumaret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Creation du fichier input.txt avec des donnees pour le test
echo -e "d\nc\na\nb" > input.txt

# Exécution de la premiere commande avec pipex
./pipex input.txt "cat" "sort" output.txt

# Execution de la commande shell equivalente et stockage du resultat dans un fichier temporaire
cat input.txt | sort > expected_output.txt

# Comparaison des resultats
if diff -q output.txt expected_output.txt > /dev/null; then
    echo -e "\033[32m[OK]\033[0m"
else
    echo -e "\033[31m[FAIL]\033[0m"
fi


echo -e "file1.txt\nfile2.txt\nfile3.txt" > input

# Execution de la deuxieme commande avec pipex
./pipex input "ls -l" "grep .txt" output.txt

# Execution de la commande shell equivalente et stockage du resultat dans un fichier temporaire
ls -l input | grep .txt > expected_output2.txt

# Comparaison des resultats
if diff -q output.txt expected_output2.txt > /dev/null; then
    echo -e "\033[32m[OK]\033[0m"
else
    echo -e "\033[31m[FAIL]\033[0m"
fi

# Nettoyage des fichiers temporaires
rm input.txt output.txt expected_output.txt expected_output2.txt input