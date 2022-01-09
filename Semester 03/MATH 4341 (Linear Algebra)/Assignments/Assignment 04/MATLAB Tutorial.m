diary on

E = eye(3)

E =

     1     0     0
     0     1     0
     0     0     1

u = E(:, 1)

u =

     1
     0
     0

E(3, 1) = 5

E =

     1     0     0
     0     1     0
     5     0     1

v = E * u

v =

     1
     0
     5

A = ones(3) + eye(3)

A =

     2     1     1
     1     2     1
     1     1     2

b = A(:, 3)

b =

     1
     1
     2

C = inv(A)

C =

    0.7500   -0.2500   -0.2500
   -0.2500    0.7500   -0.2500
   -0.2500   -0.2500    0.7500

x = A \ b

x =

     0
     0
     1

% This is a comment

% How to input a row or column vector

u = [2 4 5]

u =

     2     4     5

v = [2; 4; 5]

v =

     2
     4
     5

v = [2 4 5]'

v =

     2
     4
     5

w = 2:5

w =

     2     3     4     5

u = 1:2:7

u =

     1     3     5     7

% How to input a matrix (a row at a time)

A = [1 2 3; 4 5 6]

A =

     1     2     3
     4     5     6

A = [1 2 3
4 5 6]

A =

     1     2     3
     4     5     6

B = [1 2 3; 4 5 6]'

B =

     1     4
     2     5
     3     6

% How to create special matrices

diag(v)

ans =

     2     0     0
     0     4     0
     0     0     5

toeplitz(v)

ans =

     2     4     5
     4     2     4
     5     4     2

toeplitz(w, v)

ans =

     2     4     5
     3     2     4
     4     3     2
     5     4     3

ones(3)

ans =

     1     1     1
     1     1     1
     1     1     1

zeros(3)

ans =

     0     0     0
     0     0     0
     0     0     0

eye(3)

ans =

     1     0     0
     0     1     0
     0     0     1

rand(3)

ans =

    0.8147    0.9134    0.2785
    0.9058    0.6324    0.5469
    0.1270    0.0975    0.9575

randn(3)

ans =

    2.7694    0.7254   -0.2050
   -1.3499   -0.0631   -0.1241
    3.0349    0.7147    1.4897

ones(2, 3)

ans =

     1     1     1
     1     1     1

ones(size(A))

ans =

     1     1     1
     1     1     1

% How to change entries in a given matrix A

A(3, 2) = 7

A =

     1     2     3
     4     5     6
     0     7     0

A(3, :) = v

A =

     1     2     3
     4     5     6
     2     4     5

A(:, 2)=w
{Unable to perform assignment because the size of the left side is 3-by-1 and the size of the right side is 1-by-4.
} 
A(:, 2)=v'

A =

     1     2     3
     4     4     6
     2     5     5

A([2 3], :) = A([3 2], :)

A =

     1     2     3
     2     5     5
     4     4     6

% How to create submatrices of an m * n matrix A

A(1, 2)

ans =

     2

A(1,:)

ans =

     1     2     3

A(:, 2)

ans =

     2
     5
     4

A(2:4, 3:7)
{Index in position 1 exceeds array bounds (must not exceed 3).
} 
A(1:3, 2:3)

ans =

     2     3
     5     5
     4     6

A([2 3], :)

ans =

     2     5     5
     4     4     6

A(:)

ans =

     1
     2
     4
     2
     5
     4
     3
     5
     6

triu(A)

ans =

     1     2     3
     0     5     5
     0     0     6

tril(A)

ans =

     1     0     0
     2     5     0
     4     4     6

% Matrix multiplication and inversion

A * B

ans =

    14    32
    27    63
    30    72

A. * B
{Matrix dimensions must agree.
} 
A. * C

ans =

    0.7500   -0.5000   -0.7500
   -0.5000    3.7500   -1.2500
   -1.0000   -1.0000    4.5000

inv(A)

ans =

   -1.0000         0    0.5000
   -0.8000    0.6000   -0.1000
    1.2000   -0.4000   -0.1000

pinv(A)

ans =

   -1.0000    0.0000    0.5000
   -0.8000    0.6000   -0.1000
    1.2000   -0.4000   -0.1000

A \ B

ans =

    0.5000   -1.0000
    0.1000   -0.8000
    0.1000    2.2000

x = A \ b

x =

         0
   -0.4000
    0.6000

% Numbers and matrices associated with A

det(A)

ans =

   -10

rank(A)

ans =

     3

size(A)

ans =

     3     3

trace(A)

ans =

    12

null(A)

ans =

  3×0 empty <a href="matlab:helpPopup double" style="font-weight:bold">double</a> matrix

orth(A)

ans =

   -0.3210   -0.1169   -0.9399
   -0.6289   -0.7157    0.3038
   -0.7082    0.6885    0.1562

% Examples

E = eye(4); E(2, 1) = -3

E =

     1     0     0     0
    -3     1     0     0
     0     0     1     0
     0     0     0     1

E * A
{Error using <a href="matlab:matlab.internal.language.introspective.errorDocCallback('mtimes')" style="font-weight:bold"> * </a>
Incorrect dimensions for matrix multiplication. Check that the number of columns in the first matrix matches the number of
rows in the second matrix. To perform elementwise multiplication, use '.*'.
} 
A = eye(4)

A =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1

E * A

ans =

     1     0     0     0
    -3     1     0     0
     0     0     1     0
     0     0     0     1

B = [A b]
{Error using <a href="matlab:matlab.internal.language.introspective.errorDocCallback('horzcat')" style="font-weight:bold">horzcat</a>
Dimensions of arrays being concatenated are not consistent.
} 
b = A(:, 3)

b =

     0
     0
     1
     0

B = [A b]

B =

     1     0     0     0     0
     0     1     0     0     0
     0     0     1     0     1
     0     0     0     1     0

E = eye(3); P = E([2 1 3], :)

P =

     0     1     0
     1     0     0
     0     0     1

triu(A) + tril(A) - diag(diag(A))

ans =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1

% Built-in M-files for matrix factorizations

[L, U, P] = lu(A)

L =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1


U =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1


P =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1

e = eig(A)

e =

     1
     1
     1
     1

[S, E] = eig(A)

S =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1


E =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1

[Q, R] = qr(A)

Q =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1


R =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1

% Creating M-files

type house

function [v, beta, s] = house(x, k, classname)
%HOUSE Householder matrix that reduces a vector to a multiple of e_1.
%   [V, BETA, S] = GALLERY('HOUSE',X, K) takes an N-by-1 vector X
%   and returns V and BETA such that H*X = S*e_1,
%   where e_1 is the first column of EYE(N), ABS(S) = NORM(X),
%   and H = EYE(N) - BETA*V*V' is a Householder matrix.
%   The parameter K determines the sign of S:
%      K = 0 (default): sign(S) = -sign(X(1)) ("usual" choice),
%      K = 1:           sign(S) = sign(X(1))  (alternative choice).
%   If X is real then a further option, for real X only, is
%      K = 2:           sign(S) = 1.
%   If X is complex, then sign(X) = exp(i*arg(X)) which equals X./abs(X)
%   when X ~= 0.
%   In two special cases V = 0, BETA = 1 and S = X(1) are returned
%   (hence H = I, which is not strictly a Householder matrix):
%      - When X = 0.
%      - When X = alpha*e_1 and either K = 1, or K = 2 and alpha >= 0.

%   References:
%   [1] G. H. Golub and C. F. Van Loan, Matrix Computations, third edition,
%       Johns Hopkins University Press, Baltimore, Maryland, 1996, Sec. 5.1.
%   [2] N. J. Higham, Accuracy and Stability of Numerical Algorithms,
%       Second edition, Society for Industrial and Applied Mathematics,
%       Philadelphia, 2002, Sec. 19.1.
%   [3] G. W. Stewart, Introduction to Matrix Computations, Academic Press,
%       New York, 1973, pp. 231-234, 262.
%   [4] J. H. Wilkinson, The Algebraic Eigenvalue Problem, Oxford University
%       Press, 1965, pp. 48-50.
%
%   Nicholas J. Higham
%   Copyright 1984-2005 The MathWorks, Inc.

[n, m] = size(x);
if m > 1, error(message('MATLAB:house:ArgSize')), end
if isempty(k), k = 0; end

v = x;
nrmx2n = norm(x(2:n));
nrmx = norm([x(1) nrmx2n]);

% Quit if x is the zero vector.
if nrmx == 0, beta = ones(classname); s = zeros(classname); return, end

s = nrmx * mysign(x(1));

if k == 2
   if ~any(imag(x))
      if s < 0, k = 0; else k = 1; end
   else
      k = 0;
   end
end

if k == 0
   s = -s;
   v(1) = v(1) - s;
else
   v(1) = -nrmx2n^2 / (x(1)+s)';     % NB the conjugate.
   if v(1) == 0 % Special case where V = 0: need H = I.
      beta = ones(classname);
      return
   end
end
beta = -1/(s'*v(1));                       % NB the conjugate.

% Examples

% Separate file 'mult.m' contains following function:
% function [C] = mult(A)
% r = rank(A);
% C = A' * A;

mult(A)

ans =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1

% Seperate file 'properties.m' contains following funciton:
% function[V, D, r] = properties(A)
% [m, n] = size(A);
% if m == n
% [V, D] = eig(A);
% r = rank(A);
% else
% disp('Error: The matrix must be square');
% end

[Warning: Function properties has the same name as a MATLAB builtin. We suggest you rename the function to avoid a potential
name conflict.] 
properties(A)

ans =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1

[V, D, r] = properties(A)

V =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1


D =

     1     0     0     0
     0     1     0     0
     0     0     1     0
     0     0     0     1


r =

     4

% Saving your variables and matrices

save 'contents'
[Warning: Function properties has the same name as a MATLAB builtin. We suggest you rename the function to avoid a potential
name conflict.] 
clear
load 'contents'

% Graphics

plot (b, e)
plot (b, e, 'r+:')
plot (b, e, '--')
plot (b, e, 'o')
loglog(b, e, b', e')
semilogy(b, e, b', e')
axis([1 2 3 4])
title('height of satellite')
xlabel('time in seconds')
ylabel('height in meters')
hold
Current plot held
hold
Current plot released
print -d 'new'
Supported devices are:
    -dwin
    -dwinc
    -dmeta
    -dbitmap
    -dps
    -dpsc
    -dps2
    -dps2c
    -dpsc2
    -deps
    -depsc
    -deps2
    -deps2c
    -depsc2
    -dtiff
    -dtiffnocompression
    -dbmp
    -dhdf
    -dpng
    -dsvg
    -djpeg
    -dpcxmono
    -dpcxgray
    -dpcx16
    -dpcx256
    -dpcx24b
    -dbmpmono
    -dbmp16m
    -dbmp256
    -dpngmono
    -dpnggray
    -dpng16m
    -dpng256
    -dpbm
    -dpbmraw
    -dpgm
    -dpgmraw
    -dppm
    -dppmraw
    -dtiffpack
    -dtiff24nc
    -dpdfwrite
    -dprn
    -dprnc
help print
    <strong>print</strong> Print or save a figure or model.
      A subset of the available options is presented below. For more details
      see <a href="matlab:helpview([docroot '/matlab/ref/print.html'])" />the documentation</a>.
 
      <strong>print</strong>, by itself, prints the current figure to your default printer.
      Use the -s option to print the current model instead of the current figure.
        print         % print the current figure to the default printer
        print -s      % print the current model to the default printer
 
      <strong>print</strong>(filename, formattype) saves the current figure to a file in the
      specified format. Vector graphics, such as PDF ('-dpdf'), and encapsulated
      PostScript ('-depsc'), as well as images such as JPEG ('-djpeg') and PNG ('-dpng')
      can be created. Use '-d' to specify the formattype option
        print(fig, '-dpdf', 'myfigure.pdf'); % save to the 'myfigure.pdf' file
      The full list of formats is <a href="matlab:helpview([docroot '/matlab/ref/print.html#inputarg_formattype'])" />documented here</a>.
 
      <strong>print</strong>(printer, ...) prints the figure or model to the specified printer.
      Use '-P' to specify the printer option.
        print(fig, '-Pmyprinter'); % print to the printer named 'myprinter'
 
      <strong>print</strong>(resize,...) resizes the figure to fit the page when printing.
      The resize options are valid only for figures, and only for page
      formats (PDF, and PS) and printers. Specify resize as either
        '-bestfit'  to preserve the figure's aspect ratio or
        '-fillpage' to ignore the aspect ratio.
 
    <a href="matlab:helpview([docroot '/matlab/ref/print.html'])" />The documentation</a> contains additonal details and examples, including how to
    specify the figure or model to print, adjust the output size and
    resolution, save to the clipboard, and specify the renderer to use.
 
    See also <a href="matlab:help saveas">saveas</a>, <a href="matlab:help printpreview">printpreview</a>, <a href="matlab:help savefig">savefig</a>.

    <a href="matlab:doc print">Reference page for print</a>


diary off
