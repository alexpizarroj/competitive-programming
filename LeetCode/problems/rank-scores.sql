-- https://leetcode.com/problems/rank-scores/

select t.Score, (
    select Ranking
    from (
        select p.Score, @rownum := @rownum + 1 as Ranking
        from (
            select distinct(q.Score) as Score
            from Scores as q
            order by q.Score desc
        ) as p
        join (select @rownum := 0) as rn
    ) as r where r.Score = t.Score
) as Rank
from Scores as t
order by Rank asc;

