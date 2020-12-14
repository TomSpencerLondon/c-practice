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
	int position = 1;
	int tabs = 0;
	int spaces = 0;
	int c;
	
	while((c = getchar()) != EOF){
		if (c == ' '){
			if (position % TAB_SPACES != 0){
				spaces++;
			}else {
				spaces = 0;
				tabs++;
			}
		}else{
			for (int i = tabs; i > 0; i--){
				putchar('\t');
				tabs--;
			}	
			if (c == '\t'){
				spaces = 0;
			}else {
				for (int i = spaces; spaces > 0; i--){
					putchar(' ');
					spaces--;
				}
			}
			putchar(c);
			if (c == '\n'){
				position = 0;
			}else if (c == '\t'){
				position = position + (TAB_SPACES - (position - 1) % TAB_SPACES) - 1;
			}
		}
		position++;
	}
}