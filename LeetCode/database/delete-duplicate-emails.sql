delete p
from Person as p inner join Person as q
where p.Id > q.Id and p.Email = q.Email;
