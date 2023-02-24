# Write your MySQL query statement below
select case 
        when (A+B<=C) or (B+C<=A) or (A+C<=B) 
        then 'Not A Triangle' 
        when A=B and B=C and C=A 
        then 'Equilateral' 
        when (A=B AND B!=C) or (B=C AND A!=B) or (C=A AND C!=B) 
        -- WHEN A=B OR B=C OR A=C
        then 'Isosceles' 
        ELSE 'Scalene' 
        END AS TYPE 
  from TRIANGLES;
