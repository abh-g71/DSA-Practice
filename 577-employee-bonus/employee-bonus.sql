# Write your MySQL query statement below
Select e.name, b.bonus
from employee as e
left join Bonus as b
on e.empId = b.empId 
where bonus < 1000 OR bonus is NULL