DELETE FROM Person 
where id NOT IN (SELECT MIN(id) FROM Person 
GROUP BY email);
