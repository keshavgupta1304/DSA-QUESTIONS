-- Write your PostgreSQL query statement below
select s.student_id,max(s.student_name) as student_name,sub.subject_name,coalesce(count(e.subject_name),0) as attended_exams
from Students s
cross join Subjects sub
left join Examinations e on e.student_id=s.student_id and sub.subject_name=e.subject_name
group by s.student_id,sub.subject_name,e.subject_name
order by s.student_id,sub.subject_name;
--where