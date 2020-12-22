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

#define MARGIN_POSITION 80

int main(){
	int currentColumn = 0;
	char word[MARGIN_POSITION];
	int positionInWord = 0;
	int c;

	while((c = getchar()) != EOF) {
		if (c == '\n'){
			for (int i = 0; i < positionInWord; i++){
				putchar(word[i]);
			}
			putchar(c);
			currentColumn = 0;
			positionInWord = 0;
		}else if (c == ' ') {
			for (int i = 0; i < positionInWord; i++){
				putchar(word[i]);
			}
			putchar(c);
			if (currentColumn > MARGIN_POSITION){
				positionInWord = 0;
				currentColumn = 0;
				putchar('\n');
			}else {
				positionInWord = 0;
				currentColumn++;
			}
		}else if (c == '\t') {
			for (int i = 0; i < positionInWord; i++){
				putchar(word[i]);
			}
			putchar(c);
			if (currentColumn > MARGIN_POSITION){
				positionInWord = 0;
				currentColumn = 0;
				putchar('\n');
			}else {
			  positionInWord = 0;
			  currentColumn += 4;
			}
		} else {
			if (currentColumn > MARGIN_POSITION){
				putchar('\n');
				word[positionInWord++] = c;
				for (int i = 0; i < positionInWord; i++){
					putchar(word[i]);
				}
				positionInWord = 0;
				currentColumn = 0;
			}else {
				word[positionInWord++] = c;
				currentColumn++;
			}
		}
	}
}