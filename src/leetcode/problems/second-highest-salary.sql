-- https://leetcode.com/problems/second-highest-salary/

select p.Salary from (
    (select distinct(p.Salary) as Salary from Employee as p)
    union
    (select null as Salary)
) as p order by p.Salary desc limit 1, 1;
