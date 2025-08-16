-- Write your PostgreSQL query statement below
select manager.name
from Employee emp
join Employee manager on emp.managerId=manager.id
group by manager.id,manager.name
having count(manager.id) >=5;