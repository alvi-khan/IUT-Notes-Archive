/* #################### Task 1 #################### */
SET SERVEROUTPUT ON

DECLARE
    cur_year NUMBER := TO_NUMBER(TO_CHAR(SYSDATE, 'YYYY'));
    year_var NUMBER;

BEGIN
    IF (MOD(cur_year, 4) = 0 AND (MOD(cur_year, 100) != 0 OR MOD(cur_year, 400) = 0)) THEN
        DBMS_OUTPUT.PUT_LINE('Yes');
    ELSE
        DBMS_OUTPUT.PUT_LINE('No');
    END IF;

    year_var := cur_year - 1;
    LOOP
        IF (MOD(year_var, 4) = 0 AND (MOD(year_var, 100) != 0 OR MOD(year_var, 400) = 0)) THEN
            DBMS_OUTPUT.PUT_LINE('The last leap year was: ' || year_var);
            EXIT;
        ELSE
            year_var := year_var - 1;
        END IF;
    END LOOP;

    year_var := cur_year + 1;
    LOOP
        IF (MOD(year_var, 4) = 0 AND (MOD(year_var, 100) != 0 OR MOD(year_var, 400) = 0)) THEN
            DBMS_OUTPUT.PUT_LINE('The last leap year was: ' || year_var);
            EXIT;
        ELSE
            year_var := year_var + 1;
        END IF;
    END LOOP;
END;
/

/* #################### Task 2 #################### */

CREATE OR REPLACE FUNCTION times_table(n NUMBER, iter NUMBER)
RETURN VARCHAR2
IS
    i NUMBER := 1;
    j NUMBER;
BEGIN
    WHILE i <= n LOOP
        DBMS_OUTPUT.PUT_LINE(i || ' Table');
        DBMS_OUTPUT.PUT_LINE('----------');
        j := 1;
        WHILE j <= iter LOOP
            DBMS_OUTPUT.PUT_LINE(i || '*' || j || '=' || i*j);
            j := j + 1;
        END LOOP;
        i := i + 1;
    END LOOP;
    RETURN NULL;
END;
/

DECLARE
    n NUMBER;
    iter NUMBER;
    throw_away VARCHAR2(1);
BEGIN
    n := &n;
    iter := &iter;
    throw_away := times_table(n, iter);
END;
/

/* #################### Task 3 #################### */

DECLARE
    password_length NUMBER;
    combinations NUMBER := 1;
    chars NUMBER := 52;
BEGIN
    SELECT MAX(Password_Length) INTO password_length FROM some_table;
    WHILE password_length > 0 LOOP
        combinations := combinations * chars;
        chars := chars - 1;
        password_length := password_length - 1;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(combinations);
END;
/

/* #################### Task 4 #################### */
CREATE OR REPLACE PROCEDURE string_proc(str IN VARCHAR2)
    IS
    ind NUMBER := 1;
    str_len NUMBER := LENGTH(str);
    flag BOOLEAN := TRUE;
    print_str VARCHAR2(100);

BEGIN
    WHILE ind < str_len LOOP
        print_str := print_str || SUBSTR(str, ind, 1) || ' ';
        IF (SUBSTR(str, ind, 1) != SUBSTR(str, str_len + 1 - ind, 1)) THEN
            flag := FALSE;
        END IF;
        ind := ind + 1;
    END LOOP;
    print_str := print_str || SUBSTR(str, ind, 1);
    DBMS_OUTPUT.PUT_LINE(print_str);
    IF flag THEN
        DBMS_OUTPUT.PUT_LINE('Yes');
    ELSE
        DBMS_OUTPUT.PUT_LINE('No');
    END IF;
END;
/