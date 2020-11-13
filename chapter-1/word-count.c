#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
	int character, numberOfLines, numberOfWords, numberOfCharacters, state;
	
	state = OUT;
	
	numberOfLines = numberOfWords = numberOfCharacters = 0;
	
	while ((character = getchar()) != EOF) {
		++numberOfCharacters;
		if (character == '\n')
			++numberOfLines;
		if (character == ' ' || character == '\n' || character == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++numberOfWords;
		}
	}
	
	printf("%d %d %d\n", numberOfLines, numberOfWords, numberOfCharacters);
}