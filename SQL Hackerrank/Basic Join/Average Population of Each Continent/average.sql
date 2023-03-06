select cn.continent, floor(avg(c.population)) from city c
join country cn 
on cn.code=c.countrycode
group by cn.continent
