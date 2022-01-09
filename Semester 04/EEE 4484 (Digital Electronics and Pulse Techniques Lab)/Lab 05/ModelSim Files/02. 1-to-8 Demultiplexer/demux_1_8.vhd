LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY demux_1_8 IS
    PORT (
	input : IN std_logic;
        sel : IN std_logic_vector(2 DOWNTO 0);
        output : OUT std_logic_vector(7 DOWNTO 0)
    );
END ENTITY;

ARCHITECTURE behavioral OF demux_1_8 IS

BEGIN
    PROCESS (input, sel)
    BEGIN
        output <= "00000000";
        
        CASE sel IS
            WHEN "000" => output(0) <= input;
            WHEN "001" => output(1) <= input;
            WHEN "010" => output(2) <= input;
            WHEN "011" => output(3) <= input;
            WHEN "100" => output(4) <= input;
            WHEN "101" => output(5) <= input;
            WHEN "110" => output(6) <= input;
            WHEN "111" => output(7) <= input;
            WHEN OTHERS => output <= "00000000";
        END CASE;
    END PROCESS;
END ARCHITECTURE behavioral;