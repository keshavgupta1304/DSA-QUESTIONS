-- Write your PostgreSQL query statement below
select round(count(a1.player_id)/(select count(distinct player_id) from Activity)::numeric,2) as fraction
from activity a1
where (a1.player_id,a1.event_date-interval '1 day') in
(
    select player_id,min(event_date)
    from Activity 
    group by player_id
)

--join Activity a2 on a1.player_id=a2.player_id and a1.event_date=a2.event_date + INTERVAL '1 day'
