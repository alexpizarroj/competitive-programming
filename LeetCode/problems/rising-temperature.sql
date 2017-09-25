-- https://leetcode.com/problems/rising-temperature/

select p.Id
from Weather as p
join Weather as q on to_days(p.Date) = to_days(q.Date) + 1
where p.Temperature > q.Temperature;
