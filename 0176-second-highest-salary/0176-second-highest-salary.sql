SELECT MAX(salary) as SecondHighestSalary from Employee
WHERE salary < (Select MAX(salary) from Employee);