LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY tb_full_adder IS
END tb_full_adder;

ARCHITECTURE behavior OF tb_full_adder IS
	COMPONENT full_adder
		PORT (
			Num1, Num2, CarryIn : IN std_logic;
			Sum, CarryOut : OUT std_logic
		);
	END COMPONENT;

	SIGNAL tb_Num1, tb_Num2, tb_CarryIn : std_logic := '0';
	SIGNAL tb_Sum, tb_CarryOut : std_logic;

BEGIN
	uut : full_adder
	PORT MAP(
		Num1 => tb_Num1, 
		Num2 => tb_Num2, 
		CarryIn => tb_CarryIn, 
		Sum => tb_Sum, 
		CarryOut => tb_CarryOut
	);

	stim_proc : PROCESS
	BEGIN
		WAIT FOR 100 ns;

		tb_Num1 <= '1';
		tb_Num2 <= '0';
		tb_CarryIn <= '0';
		WAIT FOR 50 ns;

		tb_Num1 <= '0';
		tb_Num2 <= '1';
		tb_CarryIn <= '0';
		WAIT FOR 50 ns;

		tb_Num1 <= '1';
		tb_Num2 <= '1';
		tb_CarryIn <= '0';
		WAIT FOR 50 ns;

		tb_Num1 <= '0';
		tb_Num2 <= '0';
		tb_CarryIn <= '1';
		WAIT FOR 50 ns;

		tb_Num1 <= '1';
		tb_Num2 <= '0';
		tb_CarryIn <= '1';
		WAIT FOR 50 ns;

		tb_Num1 <= '0';
		tb_Num2 <= '1';
		tb_CarryIn <= '1';
		WAIT FOR 50 ns;

		tb_Num1 <= '1';
		tb_Num2 <= '1';
		tb_CarryIn <= '1';
		WAIT FOR 50 ns;

	END PROCESS;
END;