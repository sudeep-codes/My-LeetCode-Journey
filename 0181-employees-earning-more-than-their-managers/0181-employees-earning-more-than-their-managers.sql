# Write your MySQL query statement below
select e1.name AS employee
from employee as e1
join employee as e2
on e1.managerID=e2.id
where e1.salary>e2.salary;