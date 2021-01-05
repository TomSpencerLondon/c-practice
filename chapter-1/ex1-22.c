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
int currentColumn;
char word[MARGIN_POSITION];
int positionInWord;
int c;

void flushBuffer(){
	for (int i = 0; i < positionInWord; i++){
		putchar(word[i]);
	}
	positionInWord = 0;
}

void reset(){
	flushBuffer();
	putchar(c);
	currentColumn = 0;
}

int main(){
	currentColumn = 0;
	positionInWord = 0;

	while((c = getchar()) != EOF) {
		if (c == '\n'){
			reset();
		}else if (c == ' ' || c == '\t') {
			flushBuffer();
			putchar(c);

			if (currentColumn > MARGIN_POSITION){
				currentColumn = 0;
				putchar('\n');
			}else {
				if (c == ' '){
					currentColumn++;
				}else if (c == '\t'){
					currentColumn += 4;
				}
			}
		} else {
			if (currentColumn > MARGIN_POSITION){
				putchar('\n');
				word[positionInWord++] = c;
				flushBuffer();
				
				currentColumn = 0;
			}else {
				word[positionInWord++] = c;
				currentColumn++;
			}
		}
	}
}