# Write your MySQL query statement below

# Using UNION
select employee_id from employees where employee_id not in (select employee_id from salaries)
union
select employee_id from salaries where employee_id not in (select employee_id from employees)
order by employee_id;

# Using LEFT JOIN
# select e.employee_id from employees as e
# left join salaries s on e.employee_id=s.employee_id
# where salary is null
# union
# select s.employee_id from salaries as s
# left join employees e on s.employee_id=e.employee_id
# where name is null
# order by employee_id;