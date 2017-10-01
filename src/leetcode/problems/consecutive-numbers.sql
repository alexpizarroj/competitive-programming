-- https://leetcode.com/problems/consecutive-numbers/

select distinct(t.Num)
from Logs as t
join Logs as t2 on t2.Id = t.Id - 1
join Logs as t3 on t3.Id = t.Id - 2
where t.Num = t2.Num and t2.Num = t3.Num
order by t.Num;
