#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0

int main(){
	int character, i, numberOfCharacters, state;
	int len;
	int maxValue;
	int overFlow;
	int wordLength[MAXWORD];
	
	state = OUT;
	numberOfCharacters = 0;
	overFlow = 0;
	
	for (i = 0; i < MAXWORD; ++i){
		wordLength[i] = 0;
	}
	
	while ((character = getchar()) != EOF){
		if (character == ' ' || character == '\n' || character == '\t'){
			state = OUT;
			if (numberOfCharacters > 0){
				
				if (numberOfCharacters < MAXWORD){
					++wordLength[numberOfCharacters];
				}else{
					++overFlow;
				}
			}	
			numberOfCharacters = 0;
		}else if (state == OUT) {
			state = IN;
			numberOfCharacters = 1;
		}else {
			++numberOfCharacters;
		}
	}
	
	maxValue = 0;
	for (i = 1; i < MAXWORD; ++i)
		if (wordLength[i] > maxValue)
			maxValue = wordLength[i];
	
	for (i = 1; i < MAXWORD; ++i){
		printf("%5d - %5d : ", i, wordLength[i]);
		if (wordLength[i] > 0){
			if ((len = wordLength[i] * MAXHIST / maxValue) <= 0)
				len = 1;
		}else{
			len = 0;
		}
		while (len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if (overFlow > 0)
		printf("There are %d words >= %d\n", overFlow, MAXWORD);
}