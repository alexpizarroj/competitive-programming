-- https://leetcode.com/problems/department-highest-salary/

select t1.Name as Department, t2.Name as Employee, t1.TopSalary as Salary
from (
    select d.Id, d.Name, max(e.Salary) as TopSalary
    from Department as d
    join Employee as e on d.Id = e.DepartmentId
    group by d.Id, d.Name
) as t1
join Employee t2 on t1.Id = t2.DepartmentId
where t2.Salary = t1.TopSalary;
