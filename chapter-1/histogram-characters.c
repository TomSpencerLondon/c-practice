# include <stdio.h>

#define NUMBER_OF_LETTERS 26;

int main() {
	int letters;
	letters = NUMBER_OF_LETTERS;
	
	int i;
	int characterFrequencies[letters];
	int character;
	
	
	char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	

	
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
	
	
	int maxOccurrence = 0;
	
	for (i = 0; i < letters; i++){
		if (characterFrequencies[i] > maxOccurrence){
			maxOccurrence = characterFrequencies[i];
		}
	}
	
	int el;
	
	for (i = 0; i <= maxOccurrence; i++){
		for (el = 0; el < letters; el++){
			if ((characterFrequencies[el] == maxOccurrence - i) && (characterFrequencies[el] > 0)){
				printf("- ");
			}else if ((characterFrequencies[el] > maxOccurrence - i) && characterFrequencies[el] > 0) {
				printf("| ");
			}else {
				printf("  ");
			}
		}
		printf("\n");
	}
	
	for (el = 0; el < letters; el++){
		if (characterFrequencies[el] > 0){
			printf("- ");
		}else {
			printf("  ");
		}
	}
	printf("\n");
	
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
}