#include <stdio.h>
#define TAB_LENGTH 8

int main(){
	char c;
	int position = 1;
	int number_of_blanks;
	
	while ((c = getchar()) != EOF){
		if (c == '\t'){
			number_of_blanks = TAB_LENGTH - (position - 1) % TAB_LENGTH;
			while(number_of_blanks > 0){
				putchar(' ');
				++position;
				--number_of_blanks;
			}
		}else if (c == '\n'){
			putchar(c);
			position = 1;
		}else {
			putchar(c);
			++position;
		}
	}
}