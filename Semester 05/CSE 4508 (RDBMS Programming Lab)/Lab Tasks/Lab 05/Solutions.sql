/* ========== TASK A ========== */

CREATE TABLE occupation (
    id NUMBER(9, 0),
    general VARCHAR2(20),
    specific VARCHAR2(20),
    salary NUMBER(9, 2),
  	CONSTRAINT pk_occupation PRIMARY KEY (id)
);

INSERT INTO occupation VALUES (1, 'Teacher', 'School', 50000.00);
INSERT INTO occupation VALUES (2, 'Engineer', 'CSE', 132000.00);
INSERT INTO occupation VALUES (3, 'Teacher', 'University', 103000.00);
INSERT INTO occupation VALUES (4, 'Teacher', 'School', 52500.00);
INSERT INTO occupation VALUES (5, 'Engineer', 'Mechanical', 125000.00);
INSERT INTO occupation VALUES (6, 'Doctor', 'Neurology', 320000.00);
INSERT INTO occupation VALUES (7, 'Lawyer', 'Corporate', 250000.00);
INSERT INTO occupation VALUES (8, 'Doctor', 'General Practitioner', 150000.00);
INSERT INTO occupation VALUES (9, 'Teacher', 'School', 48000.00);
INSERT INTO occupation VALUES (10, 'Teacher', 'University', 115000.00);

/* ========== Part 1 ========== */

SELECT COUNT(*) grp_size, general, specific
FROM occupation
GROUP BY general, specific
ORDER BY grp_size DESC;

/* ========== Part 2 ========== */

SELECT general, MAX(salary), MIN(salary), AVG(salary)
FROM occupation
GROUP BY general;

/* ========== Part 3 ========== */

SELECT general, AVG(salary)
FROM occupation
GROUP BY general
HAVING AVG(salary) >= (
    SELECT AVG(salary) 
    FROM occupation
);

/* ========== Part 4 ========== */

CREATE VIEW group_salaries AS
    SELECT general, AVG(salary) avg_salary
    FROM occupation
    GROUP BY general;

SELECT general, avg_salary
FROM group_salaries
WHERE avg_salary = (
    SELECT MAX(avg_salary) 
    FROM group_salaries
);

/* ========== TASK B ========== */

CREATE TABLE grades(
    id NUMBER(9, 0),
    department VARCHAR2(3),
    programme VARCHAR2(3),
    course_code VARCHAR2(8),
    grade VARCHAR2(3),
    CONSTRAINT pk_grades PRIMARY KEY (id),
    CONSTRAINT chk_prog CHECK (programme IN ('BSc','HD')),
    CONSTRAINT chk_grad CHECK (grade in ('A+','A','A-','B+','B','B-','C+','C','C-','D+','D','D-','E+','E','E-','F'))
);

INSERT INTO grades VALUES (1, 'CSE', 'BSc', 'CSE 4105', 'A');
INSERT INTO grades VALUES (2, 'EEE', 'BSc', 'EEE 4301', 'B+');
INSERT INTO grades VALUES (3, 'CEE', 'HD', 'CEE 4105', 'A-');
INSERT INTO grades VALUES (4, 'CSE', 'BSc', 'CSE 4507', 'C-');
INSERT INTO grades VALUES (5, 'CSE', 'BSc', 'CSE 4549', 'A');
INSERT INTO grades VALUES (6, 'CEE', 'HD', 'CEE 4201', 'A+');
INSERT INTO grades VALUES (7, 'MCE', 'BSc', 'MCE 4105', 'A');
INSERT INTO grades VALUES (8, 'CSE', 'BSc', 'CSE 4203', 'A+');
INSERT INTO grades VALUES (9, 'CSE', 'BSc', 'CSE 4701', 'A');
INSERT INTO grades VALUES (10, 'EEE', 'BSc', 'EEE 4307', 'B');

/* ========== Part 1 ========== */

SELECT department, programme, course_code, grade, COUNT(*)
FROM grades
GROUP BY ROLLUP(department, programme, course_code, grade)
ORDER BY department, programme, course_code, grade;

/* ========== Part 2 ========== */

SELECT department, programme, course_code, grade, COUNT(*)
FROM grades
GROUP BY CUBE(department, programme, course_code, grade)
ORDER BY department, programme, course_code, grade;