# Write your MySQL query statement below
select v1.id from weather v1 join weather v2 on datediff(v1.recordDate, v2.recordDate) = 1 and v1.temperature > v2.temperature; 