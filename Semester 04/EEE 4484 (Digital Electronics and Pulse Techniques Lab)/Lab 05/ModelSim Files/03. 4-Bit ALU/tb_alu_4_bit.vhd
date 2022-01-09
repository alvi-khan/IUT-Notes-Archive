LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
 
ENTITY tb_alu_4_bit IS
END tb_alu_4_bit;
 
ARCHITECTURE behavioral OF tb_alu_4_bit IS
 
    COMPONENT alu_4_bit
        PORT (
            num1, num2 : IN signed(3 DOWNTO 0);
            sel : IN std_logic_vector(1 DOWNTO 0);
            result: OUT signed(3 DOWNTO 0)
        );
    END COMPONENT;

    SIGNAL tb_num1, tb_num2 : signed(3 DOWNTO 0) := (OTHERS => '0');
    SIGNAL tb_sel : std_logic_vector(1 DOWNTO 0) := (OTHERS => '0');
    SIGNAL tb_result : signed(3 DOWNTO 0);
 
BEGIN
    uut : alu_4_bit
    PORT MAP(
        num1 => tb_num1, 
        num2 => tb_num2, 
        sel => tb_sel, 
        result => tb_result
    );

    stim_proc : PROCESS
    BEGIN
        WAIT FOR 100 ns;

        tb_num1 <= "1001";
        tb_num2 <= "1111";
        tb_sel <= "00";
        WAIT FOR 50 ns;

        tb_sel <= "01";
        WAIT FOR 50 ns;

        tb_sel <= "10";
        WAIT FOR 50 ns;

        tb_sel <= "11";
    END PROCESS;
END behavioral;