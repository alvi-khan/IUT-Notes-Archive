/* ========== Task A ========== */

CREATE TABLE employee (
    salary NUMBER(9, 0),
    designation VARCHAR2(20)
);

INSERT INTO employee VALUES (6000, 'officer');
INSERT INTO employee VALUES (8000, 'assistant-officer');
INSERT INTO employee VALUES (3000, 'janitor');
INSERT INTO employee VALUES (2000, 'officer');
INSERT INTO employee VALUES (4000, 'assistant-officer');

BEGIN
    UPDATE employee
    SET salary = salary * 1.5
    WHERE (salary < 5000) AND 
    ((designation = 'officer') OR 
    (designation = 'assistant-officer'));
    
    IF SQL%NOTFOUND THEN
        DBMS_OUTPUT.PUT_LINE('0 rows affected.');
    ELSIF SQL%FOUND THEN
        DBMS_OUTPUT.PUT_LINE(SQL%ROWCOUNT || ' rows affected.');
    END IF;
END;
/

/* ========== Task B ========== */

CREATE TABLE transactions (
    user_id NUMBER(9, 0),
    amount NUMBER(9, 2),
    t_date DATE
);

INSERT INTO transactions VALUES (1, 50000, TO_DATE('2021/05/03', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (1, 450000, TO_DATE('2021/05/17', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (1, 1000, TO_DATE('2021/03/02', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (2, 500000, TO_DATE('2020/08/15', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (2, 200000, TO_DATE('2020/07/21', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (2, 400000, TO_DATE('2021/03/26', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (3, 2000000, TO_DATE('2021/02/07', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (3, 20000, TO_DATE('2020/12/15', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (3, 50000, TO_DATE('2020/03/02', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (4, 2000000, TO_DATE('2020/02/07', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (4, 20000, TO_DATE('2019/12/15', 'YYYY/MM/DD'));
INSERT INTO transactions VALUES (4, 50000, TO_DATE('2020/03/02', 'YYYY/MM/DD'));

CREATE TABLE loan_type (
    scheme NUMBER(1, 0),
    installment_number NUMBER(2, 0),
    charge NUMBER(3, 0),
    min_trans NUMBER(9, 0)
);

INSERT INTO loan_type VALUES (1, 30, 5, 2000000); 
INSERT INTO loan_type VALUES (2, 20, 10, 1000000);
INSERT INTO loan_type VALUES (3, 15, 15, 500000);

CREATE OR REPLACE FUNCTION get_scheme (id NUMBER)

RETURN NUMBER

IS

    user_total NUMBER(9, 0);

    CURSOR loan_schemes
    IS
    SELECT * FROM loan_type;
    
BEGIN

    SELECT SUM(amount) INTO user_total
    FROM transactions
    WHERE (user_id = id)
    AND
    ((SELECT MONTHS_BETWEEN(SYSDATE, TO_DATE(t_date)) FROM DUAL) <= 12);
    
    FOR record IN loan_schemes
    LOOP
    
        IF user_total >= record.min_trans THEN
            RETURN record.scheme;
        END IF;
    END LOOP;
    
    RETURN 0;
END;
/

BEGIN
DBMS_OUTPUT.PUT_LINE(get_scheme(1));
END;
/