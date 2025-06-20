SELECT t1.name AS Employee from Employee t1 
JOIN Employee t2 
ON
t1.managerId = t2.id
where t1.salary > t2.salary;