// Write a program entab that replaces strings of blanks
// by the minimum number of tabs and blanks to achieve the same spacing.
// Use the same tab stops as for detab.
// When either a tab or a single blank would suffice to reach a
// tab stop, which should be given preference?

// 1st position reset 0 at '\n'
// In word? 
// if not in word and position before tab stop
// replace spaces with tabs
// If in word don't
#include <stdio.h>

#define TAB_SPACES 8

int main() {
	int spaces = 0;
	int column = 0;
	int c;
	while((c = getchar()) != EOF){
		column++;
		
		if (column % TAB_SPACES == 0 && c == ' '){
			putchar('\t');
			spaces = 0;
		}else if (c == ' '){
			spaces++;
		}else if (c == '\n'){
			column = 0;
			spaces = 0;
		}else {
			for (int i = 0; i < spaces; i++){
				putchar(' ');
			}
			spaces = 0;
			putchar(c);
			
		}
	}
}