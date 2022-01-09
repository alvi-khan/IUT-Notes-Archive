LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY alu_4_bit IS
    PORT (
        num1, num2 : IN signed(3 DOWNTO 0);
        sel : IN std_logic_vector (1 DOWNTO 0);
        result : OUT signed(3 DOWNTO 0)
    );
END alu_4_bit;

ARCHITECTURE behavioral OF alu_4_bit IS
BEGIN
    PROCESS (num1, num2, sel)
    BEGIN
        
        CASE sel IS
            WHEN "00" => result <= num1 + num2;
            WHEN "01" => result <= num1 - num2;
            WHEN "10" => result <= num1 AND num2;
            WHEN "11" => result <= num1 OR num2;
            WHEN OTHERS => NULL;
		END CASE;
 
	END PROCESS;

END behavioral;