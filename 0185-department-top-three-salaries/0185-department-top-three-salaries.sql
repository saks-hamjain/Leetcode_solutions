Select d.name as Department,e.name as Employee, e.salary as Salary from 
(
    Select *,DENSE_RANK() over(partition by departmentId order by salary desc) as rnk from Employee
) e Join Department d on 
e.departmentId = d.id
where rnk <=3;