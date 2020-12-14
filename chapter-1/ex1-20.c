// Write a program detab that replaces tabs in the input with the
// proper number of blanks of space to the next tab stop. Assume a fixed set
// of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
// 1. input: tabs -> output: spaces
// 2. n = spaces between each tab
// the quick	  brown fox
// 12345678901234
#include <stdio.h>
#define TAB_SPACES 8
                     
int main() {
	int c;
	int position = 0;
	
	while((c = getchar()) != EOF){
		if (c == '\t'){
			int numberOfSpaces = TAB_SPACES - position % TAB_SPACES;
			for (int i = 0; i < numberOfSpaces; i++){
				putchar(' ');
			}
			position += numberOfSpaces;
		}else if(c == '\n') {
			putchar(c);
			position = 0;
		}else {
			putchar(c);
			position++;
		}
	}
}