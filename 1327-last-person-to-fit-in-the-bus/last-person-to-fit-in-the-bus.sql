-- Write your PostgreSQL query statement below
with total_weight_by_turn (person_name,total_weight) as
    (
        select person_name,
        sum(weight) over(order by turn) as total_weight
        from Queue
    )
select t.person_name
from total_weight_by_turn t
where t.total_weight<=1000
order by t.total_weight desc
limit 1;
