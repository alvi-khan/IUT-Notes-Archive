LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY full_adder IS
 PORT (
	Num1: IN std_logic;
	Num2: IN std_logic;
	CarryIn: IN std_logic;
	Sum: OUT std_logic;
	CarryOut: OUT std_logic
 );
END full_adder;

ARCHITECTURE behavorial OF full_adder IS
begin
 Sum <= Num1 XOR Num2 XOR CarryIn;
 CarryOut <= (Num1 AND Num2) OR (CarryIn AND Num1) OR (CarryIn AND Num2);
END behavorial;