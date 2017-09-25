# https://leetcode.com/problems/word-frequency/

#/bin/bash

declare -A freq

while read line; do
  for word in $line; do
    let "freq["$word"]++"
  done
done < words.txt

for word in "${!freq[@]}"; do
  echo "$word ${freq["$word"]}"
done | sort -n -r -k2

