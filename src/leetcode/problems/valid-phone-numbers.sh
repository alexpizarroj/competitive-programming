# https://leetcode.com/problems/valid-phone-numbers/

#Statement:https://leetcode.com/problems/valid-phone-numbers/
while read line; do [[ "$line" =~ ^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$ ]] && echo $line; done < file.txt
