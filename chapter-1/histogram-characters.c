# include <stdio.h>

#define NUMBER_OF_LETTERS 26;

int main() {
	
	int i;
	int characterFrequencies[26];
	int character;
	
	
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	int letters;
	letters = NUMBER_OF_LETTERS;
	
	for (i = 0; i < letters; i++){
		characterFrequencies[i] = 0;
	}
	
	
	while((character = getchar()) != EOF){
		if (character != ' ' || character != '\n' || character != '\t'){
			for (i = 0; i < letters; i++){
				if(character == alphabet[i]){
					characterFrequencies[i] += 1;
				}
			}
		}
	}
	
	for (i = 0; i < letters; i++){
		printf("%d", characterFrequencies[i]);
	}
}