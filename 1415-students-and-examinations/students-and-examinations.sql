# Write your MySQL query statement below
SELECT st.student_id, st.student_name, su.subject_name, count(e.student_id) as attended_exams
FROM Students st
CROSS JOIN Subjects su
LEFT JOIN Examinations e
ON e.student_id = st.student_id
AND e.subject_name = su.subject_name
GROUP BY st.student_id, st.student_name, su.subject_name
ORDER BY st.student_id, su.subject_name;