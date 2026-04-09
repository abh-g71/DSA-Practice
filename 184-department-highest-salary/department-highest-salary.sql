Select d.name as Department, e.name as Employee,e.salary as Salary
from (Select name , salary , departmentId,
      Rank() over(Partition by departmentId order by salary desc) as rnk
      from Employee ) e
Join department as d
on e.departmentId = d.id
where e.rnk = 1 