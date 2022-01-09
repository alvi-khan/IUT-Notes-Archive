%{
// Declarations
int wordCount = 0, numCount = 0, charCount = 0;
%}

%%

[a-zA-Z]+                       { wordCount++; charCount += yyleng; }	// increment word count and character count
[+-]?([0-9]*[.])?[0-9]+         { numCount++; }				// increment number count
.                               { charCount++; }			// increment character count

%%

int main()
{
	printf("Enter a string: ");
	yylex();
	printf("Words: %d, Numbers: %d, Characters: %d", wordCount, numCount, charCount);
	return 0;
}

int yywrap() { return 1; }