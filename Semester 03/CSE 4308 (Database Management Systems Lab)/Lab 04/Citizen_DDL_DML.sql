SET PAGESIZE 100;

DROP TABLE CITIZEN;

CREATE TABLE CITIZEN (
	C_ID NUMBER (3),
	C_NAME VARCHAR2 (10),
	C_HOME VARCHAR2 (10),
	AGE NUMBER (2),
	OCCUPATION VARCHAR2 (15),
	GENDER VARCHAR2 (6),
	SALARY NUMBER,
	CONSTRAINTS PK_CITIZEN PRIMARY KEY (C_ID)
);


INSERT INTO CITIZEN VALUES (1, 'Alice', 'Dhaka', 25, 'Teacher', 'Male', 50000);
INSERT INTO CITIZEN VALUES (2, 'Bob', 'Dhaka', 56, 'Service', 'Male', 60000);
INSERT INTO CITIZEN VALUES (3, 'Charlie', 'Ctg', 71, 'Retired', 'Male', 10000);
INSERT INTO CITIZEN VALUES (4, 'Erin', 'Ctg', 13, 'Student', 'Female', 500);
INSERT INTO CITIZEN VALUES (5, 'Dave', 'Dhaka', 45, 'Service', 'Male', 40000);
INSERT INTO CITIZEN VALUES (6, 'Faythe', 'Gazipur', 54, 'Doctor', 'Female', 55000);
INSERT INTO CITIZEN VALUES (7, 'Grace', 'Gazipur', 65, 'Musician', 'Female', 5000);
INSERT INTO CITIZEN VALUES (8, 'Ivan', 'Dhaka', 56, 'Engineer', 'Male', 60000);
INSERT INTO CITIZEN VALUES (9, 'Frank', 'Ctg', 23, 'Student', 'Male', 1000);
INSERT INTO CITIZEN VALUES (10, 'Micheal', 'Comilla', 32, 'Teacher', 'Male', 45000);
INSERT INTO CITIZEN VALUES (11, 'Niaj', 'Comilla', 51, 'Farmer', 'Male', 20000);
INSERT INTO CITIZEN VALUES (12, 'Heidi', 'Khulna', 15, 'Student', 'Female', 1500);
INSERT INTO CITIZEN VALUES (13, 'Ted', 'Ctg', 25, 'Business', 'Male', 100000);
INSERT INTO CITIZEN VALUES (14, 'Walter', 'Comilla', 52, 'Doctor', 'Male', 70000);
INSERT INTO CITIZEN VALUES (15, 'Victor', 'Gazipur', 53, 'Teacher', 'Male', 50000);
INSERT INTO CITIZEN VALUES (16, 'Judy', 'Dhaka', 35, 'Musician', 'Female', 50000);
INSERT INTO CITIZEN VALUES (17, 'Pat', 'Khulna', 43, 'Service', 'Male', 50000);
INSERT INTO CITIZEN VALUES (18, 'Olivia', 'Khulna', 34, 'Service', 'Female', 45000);
INSERT INTO CITIZEN VALUES (19, 'Trent', 'Ctg', 16, 'Student', 'Male', 500);
INSERT INTO CITIZEN VALUES (20, 'Peggy', 'Comilla', 32, 'Business', 'Female', 120000);
INSERT INTO CITIZEN VALUES (21, 'Wendy', 'Ctg', 25, 'Musician', 'Female', 100000);
INSERT INTO CITIZEN VALUES (22, 'Oscar', 'Gazipur', 14, 'Student', 'Male', 400);
INSERT INTO CITIZEN VALUES (23, 'Mallet', 'Dhaka', 25, 'Engineer', 'Male', 50000);