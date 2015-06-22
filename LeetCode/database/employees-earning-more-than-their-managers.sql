select p.Name as Employee
from Employee as p
join Employee as q on p.ManagerId = q.Id
where p.Salary > q.Salary;
