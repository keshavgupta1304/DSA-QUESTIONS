-- Write your PostgreSQL query statement below
select customer_id
from Customer c
group by customer_id
having count(distinct product_key) = (select count(*) from Product)
--right join Product p on c.product_key=p.product_key