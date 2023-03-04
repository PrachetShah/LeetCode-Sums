# Write your MySQL query statement below
select firstName, lastName, city, state from person
left join address on person.personid = address.personid