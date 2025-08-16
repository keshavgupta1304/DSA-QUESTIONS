-- Write your PostgreSQL query statement below
select query_name,round(avg(rating::numeric/position),2) as quality,
round(avg(case when rating < 3 then 100.00 else 0.00 end),2)
as poor_query_percentage
from Queries
group by query_name