# Write your MySQL query statement below
Select p.firstname,p.lastname,a.city,a.state
From person p
left join address a 
on p.personId = a.personId;