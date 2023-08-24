# Write your MySQL query statement below
select Weather.id 
from Weather 
join Weather as w
where Weather.temperature > w.temperature and datediff(Weather.recordDate,w.recordDate)=1
