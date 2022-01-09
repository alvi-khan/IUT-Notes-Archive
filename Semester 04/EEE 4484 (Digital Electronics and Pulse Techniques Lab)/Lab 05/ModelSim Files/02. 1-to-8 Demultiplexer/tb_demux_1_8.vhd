LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY tb_demux_1_8 IS
END tb_demux_1_8;

ARCHITECTURE behavior OF tb_demux_1_8 IS

    COMPONENT demux_1_8
        PORT (
            input : IN std_logic;
            sel : IN std_logic_vector(2 DOWNTO 0);
            output : OUT std_logic_vector(7 DOWNTO 0)
        );
    END COMPONENT;

    SIGNAL tb_input : std_logic := '0';
    SIGNAL tb_sel : std_logic_vector (2 DOWNTO 0) := (OTHERS => '0');
    SIGNAL tb_output : std_logic_vector (7 DOWNTO 0);

BEGIN
    uut : demux_1_8
    PORT MAP(
        input => tb_input, 
        sel => tb_sel, 
        output => tb_output
    );

    stim_proc : PROCESS
    BEGIN
        WAIT FOR 100 ns;

        tb_input <= '1';
        tb_sel <= "000";
        WAIT FOR 50 ns;

        tb_sel <= "001";
        WAIT FOR 50 ns;

        tb_sel <= "010";
        WAIT FOR 50 ns;

        tb_sel <= "011";
        WAIT FOR 50 ns;

        tb_sel <= "100";
        WAIT FOR 50 ns;

        tb_sel <= "101";
        WAIT FOR 50 ns;

        tb_sel <= "110";
        WAIT FOR 50 ns;

        tb_sel <= "111";
        WAIT FOR 50 ns;
		
        WAIT;
    END PROCESS;
END;