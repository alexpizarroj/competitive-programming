#/bin/bash

declare -A freq

while read line; do
  for word in $line; do
    let "freq["$word"]++"
  done
done < words.txt

for word in "${!freq[@]}"; do echo "${freq["$word"]} $word"; done |
  sort -n -r |
  while read -a line; do
    echo ${line[1]} ${line[0]}
  done
