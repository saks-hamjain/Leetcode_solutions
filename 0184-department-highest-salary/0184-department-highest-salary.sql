Select d.name as Department,e.name as Employee, e.salary as Salary
from Employee e join Department d ON 
e.departmentId = d.id
join
(Select departmentId,max(salary) as max_salary from Employee
group by departmentId)
as m on e.departmentId = m.departmentId AND e.salary = m.max_salary;