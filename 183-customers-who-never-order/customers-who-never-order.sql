# Write your MySQL query statement below
SELECT name as Customers
FROM Customers as c
left join Orders as o
ON c.id = o.customerId
where customerId is NULL