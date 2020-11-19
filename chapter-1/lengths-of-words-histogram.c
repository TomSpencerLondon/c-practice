# include <stdio.h>

#define LONGEST 10;

int main(){
	int i;
	int max;
	max = LONGEST;
	int character;
	int lengthOfWord = 0;
	int histogram[max];
	
	for (i = 0; i < 10; ++i){
		histogram[i] = 0;
	}
	
	while((character = getchar()) != EOF) {
		if (character == ' ' || character == '\n' || character == '\t'){
			if (lengthOfWord > 0){
				histogram[lengthOfWord - 1]++;
				lengthOfWord = 0;
			}
		}else {
			lengthOfWord++;
		}
	}
	
	int j;
	
	for (i = 0; i < max; ++i){
		printf("%2d ", i + 1);
		if (histogram[i] > 0){
			printf("|");
			for (j = 0; j < histogram[i]; ++j){
				printf("-");
			}
			printf("|");
		}
		
		printf("\n");
	}
	
	int maxOccurrence = 0;
	
	for(i = 0; i < max; i++){
		if (histogram[i] > maxOccurrence){
			maxOccurrence = histogram[i];
		}
	}
	
	int line;
	
	for (int line = 0; line <= maxOccurrence + 1; line++){
		for (i = 0; i < max; i++){
			if ((histogram[i] == maxOccurrence - line) && (histogram[i] > 0)) {
				printf("- ");
			}else if((histogram[i] > maxOccurrence - line) && (histogram[i] > 0)){
				if (line == maxOccurrence + 1){
					printf("- ");
				}else {
					printf("| ");
				}
			}else {
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("1 2 3 4 5 6 7 8 9 10");
}
