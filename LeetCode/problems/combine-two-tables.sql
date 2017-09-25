-- https://leetcode.com/problems/combine-two-tables/

select p.FirstName, p.LastName, q.City, q.State
from Person as p
left join Address as q on p.PersonId = q.PersonId;

