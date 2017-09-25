# https://leetcode.com/problems/transpose-file/

#Statement:https://leetcode.com/problems/transpose-file/
# m - rows, n - columns
m=0
while read -a a$m; do
  let m++
done < file.txt
n=${#a0[@]}

for (( j=0; j<${n}; j++ )); do
  for (( i=0; i<${m}; i++ )); do
    ref=a$i[$j]
    if [[ i -gt 0 ]]; then echo -n " "; fi
    echo -n ${!ref}
  done
  echo
done

