diary on

% Problem 1

A = [2 3; 4 5]

A =

     2     3
     4     5

x = [1; -7]

x =

     1
    -7

b = [24; 5]

b =

    24
     5

A * x == b

ans =

  2×1 <a href="matlab:helpPopup logical" style="font-weight:bold">logical</a> array

   0
   0

% Thus, Ax is not equal to b


% Problem 2

A = eye(3)

A =

     1     0     0
     0     1     0
     0     0     1

v = [3 : 5]'

v =

     3
     4
     5

A * v

ans =

     3
     4
     5

v' * v

ans =

    50

v * A
{Error using <a href="matlab:matlab.internal.language.introspective.errorDocCallback('mtimes')" style="font-weight:bold"> * </a>
Incorrect dimensions for matrix multiplication. Check that the number of columns in the first matrix matches the number of
rows in the second matrix. To perform elementwise multiplication, use '.*'.
} 


% Problem 3

A = ones(4)

A =

     1     1     1     1
     1     1     1     1
     1     1     1     1
     1     1     1     1

v = ones(4, 1)

v =

     1
     1
     1
     1

A * v

ans =

     4
     4
     4
     4

B = eye(4) + ones(4)

B =

     2     1     1     1
     1     2     1     1
     1     1     2     1
     1     1     1     2

w = zeros(4, 1) + 2 * ones(4, 1)

w =

     2
     2
     2
     2

B * w

ans =

    10
    10
    10
    10



% Problem 4

P = pascal(4)

P =

     1     1     1     1
     1     2     3     4
     1     3     6    10
     1     4    10    20

inv(P)

ans =

    4.0000   -6.0000    4.0000   -1.0000
   -6.0000   14.0000  -11.0000    3.0000
    4.0000  -11.0000   10.0000   -3.0000
   -1.0000    3.0000   -3.0000    1.0000




% Problem 5

L = abs(pascal(4, 1))

L =

     1     0     0     0
     1     1     0     0
     1     2     1     0
     1     3     3     1

P == L * L'

ans =

  4×4 <a href="matlab:helpPopup logical" style="font-weight:bold">logical</a> array

   1   1   1   1
   1   1   1   1
   1   1   1   1
   1   1   1   1

% P is equal to LL'

diary off