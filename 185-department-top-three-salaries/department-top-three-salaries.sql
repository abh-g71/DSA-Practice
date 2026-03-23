# Write your MySQL query statement below
Select d.name as Department, e.name as Employee, e.Salary
from (
    Select*,
       DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rnk 
       from employee
) e
JOIN Department as d
on e.departmentId = d.id

where rnk <=3