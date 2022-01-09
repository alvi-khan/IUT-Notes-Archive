%{
// Declarations
int wordCount = 0, numCount = 0, charCount = 0;
%}

%%

[a-zA-Z]+                       { wordCount++; charCount += yyleng; }	// increment word count and character count
[+-]?([0-9]*[.])?[0-9]+         { numCount++; }				// increment number count
.                               { charCount++; }			// increment character count

%%

int main(argc, argv)
int argc;
char **argv;
{
	if (argc > 1) {
		FILE *file;
		file = fopen(argv[1], "r");
		if (!file) {
			fprintf(stderr, "Could not open %s\n", argv[1]);
			exit(1);
		}
		yyin = file;
	}
	yylex();
	printf("Words: %d, Numbers: %d, Characters: %d", wordCount, numCount, charCount);
	return 0;
}

int yywrap() { return 1; }