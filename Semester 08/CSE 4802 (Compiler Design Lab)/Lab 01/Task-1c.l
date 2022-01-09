%{
// Declarations
int wordCount = 0, numCount = 0, charCount = 0;
int totalWordCount = 0, totalNumCount = 0, totalCharCount = 0;
%}

%%

[a-zA-Z]+                       { wordCount++; charCount += yyleng; totalWordCount++; totalCharCount += yyleng; }	// increment word count and character count
[+-]?([0-9]*[.])?[0-9]+         { numCount++; totalNumCount++; }	// increment number count
.                               { charCount++; totalCharCount++; }	// increment character count

%%

int main(argc, argv)
int argc;
char **argv;
{
	if (argc > 1) {
		printf("file_name words, numbers, characters");
		int i = 0;
		for(i=1; i<argc; i++) {
			FILE *file;
			file = fopen(argv[i], "r");
			if (!file) {
				fprintf(stderr, "Could not open %s\n", argv[i]);
				exit(1);
			}
			yyin = file;
			yylex();
			printf("%s %d, %d, %d", argv[i], wordCount, numCount, charCount);
			wordCount = 0, numCount = 0, charCount = 0;
		}
	}
	printf("\ntotal %d, %d, %d", totalWordCount, totalNumCount, totalCharCount);
	return 0;
}

int yywrap() { return 1; }