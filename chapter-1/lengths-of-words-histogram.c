# include <stdio.h>

#define LONGEST 10;

int main(){
	int i;
	int max;
	max = LONGEST;
	int character;
	int lengthOfWord = 0;
	int wordCounts[max];
	
	for (i = 0; i < 10; ++i){
		wordCounts[i] = 0;
	}
	
	while((character = getchar()) != EOF) {
		if (character == ' ' || character == '\n' || character == '\t'){
			if (lengthOfWord > 0){
				wordCounts[lengthOfWord - 1]++;
				lengthOfWord = 0;
			}
		}else {
			lengthOfWord++;
		}
	}
	
	int j;
	
	for (i = 0; i < max; ++i){
		printf("%2d ", i + 1);
		if (wordCounts[i] > 0){
			printf("|");
			for (j = 0; j < wordCounts[i]; ++j){
				printf("-");
			}
			printf("|");
		}
		
		printf("\n");
	}
	
	int maxOccurrence = 0;
	
	for (i = 0; i < max; i++){
		if (wordCounts[i] > maxOccurrence){
			maxOccurrence = wordCounts[i];
		}
	}
	
	int column;
	int row;
	
	for (row = maxOccurrence + 1; row >= 0; row--){
		for (column = 0; column < max; column++){
			if ((wordCounts[column] + 1 == row) && (wordCounts[column] > 0)){
				printf("- ");
			}else if((row == 0) && wordCounts[column] > 0) {
				printf("- ");
			}else if ((wordCounts[column] + 1 > row) && wordCounts[column] > 0) {
				printf("| ");
			}else {
				printf("  ");
			}
		}
		printf("\n");
	}
	//
	// for (column = 0; column < max; column++){
	// 	if (wordCounts[column] > 0){
	// 		printf("- ");
	// 	}else {
	// 		printf("  ");
	// 	}
	// }
	// printf("\n");
	
	printf("1 2 3 4 5 6 7 8 9 10");
}










