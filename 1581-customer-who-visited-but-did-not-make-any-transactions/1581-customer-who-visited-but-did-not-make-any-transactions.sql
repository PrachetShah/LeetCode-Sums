# Write your MySQL query statement below
select customer_id, count(visits.visit_id) as count_no_trans 
from visits
left join 
transactions on visits.visit_id = transactions.visit_id
where transactions.visit_id is NULL
group by customer_id