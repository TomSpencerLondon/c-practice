#include <stdio.h>

int main(){
	int character, i, numberOfWhite, numberOfOther;
	
	numberOfWhite = numberOfOther = 0;
	
	int numberOfDigit[10];
	
	for (i = 0; i < 10; ++i){
		numberOfDigit[i] = 0;
	}
	
	while ((character = getchar())  != EOF)
		if (character >= '0' && character <= '9')
			++numberOfDigit[character-'0'];
		else if (character == ' ' || character == '\n' || character == '\t')
			++numberOfWhite;
		else
			++numberOfOther;
	
	printf("digits =");
	for (i = 0; i < 10; ++i)
		printf(" %d", numberOfDigit[i]);
	printf(", white space = %d, other = %d\n", numberOfWhite, numberOfOther);
}