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
}
