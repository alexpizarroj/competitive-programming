#/bin/bash

cur=1
while read line; do
  if [[ $cur -eq 10 ]]; then
    echo $line
  fi
  let "cur++"
done < file.txt
