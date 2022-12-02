# Write your MySQL query statement below
Select A.player_id, MIN(A.event_date) AS first_login
FROM Activity A
GROUP BY A.player_id