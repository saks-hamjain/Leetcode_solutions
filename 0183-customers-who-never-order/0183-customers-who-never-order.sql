SELECT name AS Customers 
 FROM Customers
where id NOT IN (SELECT distinct customerId from Orders);