-- AC
select distinct(t.Num)
from Logs as t
join Logs as t2 on t2.Id = t.Id - 1
join Logs as t3 on t3.Id = t.Id - 2
where t.Num = t2.Num and t2.Num = t3.Num
order by t.Num;

/*
-- TLE
select distinct(t.Num)
from Logs as t
where 2 = (
    select count(*)
    from Logs as t2
    where (t2.Id = t.Id-2 or t2.Id = t.Id-1) and t2.Num = t.Num
)
order by t.Num;
*/