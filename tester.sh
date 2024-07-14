#!/bin/bash

clear

make
make bonus

clear

./checker_linux "42 " -42" " 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "${RED}25.[KO] ${DEF_COLOR}\n";
  else
  	printf "${GREEN}25.[OK] ${DEF_COLOR}\n";
  	break
  fi
done < test_check.txt
else
	printf "${RED}25.[KO] ${DEF_COLOR}\n";
fi