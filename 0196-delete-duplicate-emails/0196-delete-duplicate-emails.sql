DELETE FROM Person 
where id NOT IN (select ID FROM ( SELECT MIN(id) as ID FROM Person 
GROUP BY email)
AS temp);
