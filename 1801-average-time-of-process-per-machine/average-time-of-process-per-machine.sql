-- Write your PostgreSQL query statement below
select machine_id,round(avg(endtime-starttime)::numeric,3) as processing_time
from (select machine_id,process_id,
        max(case when activity_type='start'
                then timestamp else 0
        end) as startTime,
        max(case when activity_type='end'
                then timestamp else 0
        end) as endTime
        from Activity
        group by machine_id,process_id
    )
group by machine_id;
