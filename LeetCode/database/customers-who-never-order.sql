select p.Name
from Customers as p
left join Orders as q on p.Id = q.CustomerId
where q.CustomerId is null;
