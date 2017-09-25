-- https://leetcode.com/problems/nth-highest-salary/

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN
  set N = N - 1;
  return (
    select distinct(Salary) from Employee order by Salary desc LIMIT N, 1
  );
END
