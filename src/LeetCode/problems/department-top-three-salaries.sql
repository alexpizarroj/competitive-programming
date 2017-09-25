-- https://leetcode.com/problems/department-top-three-salaries/

select d.Name as Department, e.Name as Employee, e.Salary as Salary
from Employee as e
join Department as d on d.Id = e.DepartmentId
where 3 > (
    select count(distinct(e2.Salary))
    from Employee as e2
    where e2.Salary > e.Salary
    and e2.DepartmentId = e.DepartmentId
);
