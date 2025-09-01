Select d.name as Department,e.name as Employee ,e.salary as Salary from employee as e
join department as d on e.departmentId = d.id
join (select max(salary) as salary, departmentId from employee group by departmentId) as t
on e.departmentId = t.departmentId and e.salary = t.salary;