-- https://leetcode.com/problems/duplicate-emails/

select q.Email
from Person as q
group by q.Email
having count(*) > 1;
