-- Write your PostgreSQL query statement below

select sq.user_id,coalesce(round(max(total_confirmed)::numeric / nullif(max(total_confirmed) + max(total_timeout),0), 2), 0)
 as confirmation_rate--max(total_confirmed) as total_confirmed,max(total_timeout) as total_timeout
from (
    select s.user_id,c.action,
        case when 
        action = 'confirmed'
        then count(action)
        else 0 end as 
    total_confirmed,
        case when 
        action = 'timeout'
        then count(action)
        else 0 end as 
    total_timeout
    from Signups s
    left join Confirmations c on s.user_id=c.user_id
    group by s.user_id,c.action
) sq
group by sq.user_id;
-- | user_id | time_stamp          | user_id | time_stamp          | action    |
-- | ------- | ------------------- | ------- | ------------------- | --------- |
-- | 2       | 2020-07-29 23:09:44 | 2       | 2021-01-22 00:00:00 | confirmed |
-- | 2       | 2020-07-29 23:09:44 | 2       | 2021-02-28 23:59:59 | timeout   |
-- | 3       | 2020-03-21 10:16:13 | 3       | 2021-07-14 14:00:00 | timeout   |
-- | 3       | 2020-03-21 10:16:13 | 3       | 2021-01-06 03:30:46 | timeout   |
-- | 6       | 2020-12-09 10:39:37 | null    | null                | null      |
-- | 7       | 2020-01-04 13:57:59 | 7       | 2021-06-13 12:58:28 | confirmed |
-- | 7       | 2020-01-04 13:57:59 | 7       | 2021-06-12 11:57:29 | confirmed |
-- | 7       | 2020-01-04 13:57:59 | 7       | 2021-06-14 13:59:27 | confirmed |