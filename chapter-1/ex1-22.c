// Write a program to "fold" long input lines into
// two or more shorter lines after the last non-blank
// character that occurs before the n-th
// column of input. Make sure your program does 
// something intelligent
// with very long lines, and if there are no blanks
// or tabs before the specified column.
#include <string.h>
#include <stdio.h>
// the house 
// on the
// prairie

#define LINE_LENGTH 80
#define MAX_LINE 1000


int main(){
	char currentWord[MAX_LINE];
	int position = 0;
	int lengthOfWord = 0;
	int c;
	while((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n'){
			currentWord[position] = '\0';
			if (lengthOfWord + position >= LINE_LENGTH){
				printf("\n");
				lengthOfWord = position;
			}else {
				if (c == '\n'){
					lengthOfWord = 0;
				}
				if (c == '\t'){
					lengthOfWord += 4;
				}else {
					lengthOfWord++;
				}
			}
			printf("%s", currentWord);
			putchar(c);
			position = 0;
		} else {
			currentWord[position] = c;
			++position;
		}
		++lengthOfWord;
	}
}