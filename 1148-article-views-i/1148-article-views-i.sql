# Write your MySQL query statement below
# SELECT author_id AS id FROM Views 
# where author_id = viewer_id 
# GROUP BY id

SELECT DISTINCT author_id AS id FROM Views 
where author_id = viewer_id 
ORDER BY id