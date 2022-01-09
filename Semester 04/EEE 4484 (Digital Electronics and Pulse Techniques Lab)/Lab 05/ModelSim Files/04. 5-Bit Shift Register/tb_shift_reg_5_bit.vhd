LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY tb_shift_reg_5_bit IS
END ENTITY tb_shift_reg_5_bit;

ARCHITECTURE behavioral OF tb_shift_reg_5_bit IS
    COMPONENT shift_reg_5_bit
        PORT (
            input : IN STD_LOGIC_VECTOR (4 DOWNTO 0);
            clock : IN STD_LOGIC;
            output : OUT STD_LOGIC_VECTOR (4 DOWNTO 0)
        );
    END COMPONENT shift_reg_5_bit;
    
    SIGNAL tb_input : STD_LOGIC_VECTOR (4 DOWNTO 0) := (OTHERS => '0');
    SIGNAL tb_clock : STD_LOGIC := '0';
    SIGNAL tb_output : STD_LOGIC_VECTOR (4 DOWNTO 0);
    CONSTANT clock_period : TIME := 100 ns;

BEGIN
    uut : shift_reg_5_bit
    PORT MAP(
        input => tb_input, 
        clock => tb_clock, 
        output => tb_output
    );
	
    clk_process : PROCESS
    BEGIN
        tb_clock <= '0';
        WAIT FOR clock_period/2;
        tb_clock <= '1';
        WAIT FOR clock_period/2;
    END PROCESS;
	
    stim_process : PROCESS
    BEGIN
        WAIT FOR 100 ns;

        tb_input <= "00001";
        WAIT FOR 100 ns;

        tb_input <= "00010";
        WAIT FOR 100 ns;

        tb_input <= "00100";
        WAIT FOR 100 ns;

        tb_input <= "01000";
        WAIT FOR 100 ns;

        tb_input <= "10000";
        WAIT FOR 100 ns;

        tb_input <= "10001";
        WAIT FOR 100 ns;

        tb_input <= "10010";
        WAIT FOR 100 ns;

        tb_input <= "10100";
        WAIT FOR 100 ns;

        tb_input <= "11000";
        WAIT FOR 100 ns;

        tb_input <= "11010";
        WAIT FOR 100 ns;

        tb_input <= "11110";
        WAIT FOR 100 ns;

        tb_input <= "11111";
    END PROCESS;
END behavioral;
