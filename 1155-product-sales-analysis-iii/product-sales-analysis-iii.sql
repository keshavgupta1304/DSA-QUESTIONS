-- Write your PostgreSQL query statement below
select s1.product_id,s1.year as first_year,s1.quantity,s1.price
from Sales s1
where (s1.product_id,s1.year) in
(
    select product_id,min(year)
    from Sales s2
    group by product_id
)
