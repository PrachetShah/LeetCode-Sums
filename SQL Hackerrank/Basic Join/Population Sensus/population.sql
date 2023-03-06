select sum(c.population) from city c 
join country cn on c.countrycode=cn.code 
where cn.continent='Asia'
