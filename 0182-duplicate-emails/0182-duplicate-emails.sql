with cte as (
    select id,email,count(*) from Person
    GROUP BY email
    HAVING count(*) > 1
)
SELECT email AS Email 
FROM cte;