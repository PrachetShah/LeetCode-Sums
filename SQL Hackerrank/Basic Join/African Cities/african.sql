select c.name from city c
join country cn on cn.code=c.countrycode
where cn.continent='Africa'
