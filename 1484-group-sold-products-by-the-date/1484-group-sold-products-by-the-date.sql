# Write your MySQL query statement below
SELECT  
	sell_date,
	(COUNT(sell_date ) ) as num_sold ,
	GROUP_CONCAT(distinct product  ORDER BY product) as products 
FROM 
	(SELECT DISTINCT sell_date,product FROM Activities) as Activities
GROUP BY sell_date;