# include <stdio.h>

#define LONGEST 10;

int main(){
	
	char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int letterCounts[26];
	int i;
	int character;
	
	
	for (i = 0; i < 26; ++i){
		letterCounts[i] = 0;
	}
	
	while((character = getchar()) != EOF) {
		if (character != ' ' || character != '\n' || character != '\t'){
			for (i = 0; i < 26; i++){
				if (letters[i] == character){
					letterCounts[i] += 1;
				}
			}
		}
	}
	
	int j;
	
	for (i = 0; i < 26; ++i){
		if (letterCounts[i] > 0){
			printf("%2c ", letters[i]);
		}
		if (letterCounts[i] > 0){
			printf("|");
			for (j = 0; j < letterCounts[i]; ++j){
				printf("-");
			}
			printf("|");
			printf("\n");
		}
	}
	
	int maxOccurrence = 0;
	
	for (i = 0; i < 26; i++){
		if (letterCounts[i] > maxOccurrence){
			maxOccurrence = letterCounts[i];
		}
	}
	
	int column;
	int row;
	
	for (row = maxOccurrence + 1; row >= 0; row--){
		for (column = 0; column < 26; column++){
			if ((letterCounts[column] + 1 == row) && (letterCounts[column] > 0)){
				printf("- ");
			}else if((row == 0) && letterCounts[column] > 0) {
				printf("- ");
			}else if ((letterCounts[column] + 1 > row) && letterCounts[column] > 0) {
				printf("| ");
			}else {
				printf("");
			}
		}
		printf("\n");
	}
	
	for (i = 0; i < 26; i++){
		if (letterCounts[i] > 0){
			printf("%c ", letters[i]);
		}
	}
	
	// printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
}










