LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY shift_reg_5_bit IS
    PORT (
        input : IN STD_LOGIC_VECTOR (4 DOWNTO 0);
        clock : IN STD_LOGIC;
        output : OUT STD_LOGIC_VECTOR (4 DOWNTO 0)
    );
END ENTITY shift_reg_5_bit;

ARCHITECTURE behavioral OF shift_reg_5_bit IS
BEGIN
    PROCESS (clock, input)
    BEGIN
        IF (clock'EVENT AND clock = '1') THEN
            output <= input;
        END IF;
    END PROCESS;
END behavioral;
