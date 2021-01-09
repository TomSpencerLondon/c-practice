// Write a program to remove all comments
// from a C program
// Don't forget to handle quoted strings and character constants
// properly. C comments do not nest
#include <string.h>
#include <stdio.h>
// the house 
// on the
// prairie

#define MARGIN_POSITION 80

int main(){
	int c;
	int d;
	int inSingleLineComment = 0;
	int inMultiLineComment = 0;
	while((c = getchar()) != EOF) {
		if (inSingleLineComment == 1){
			if (c == '\n'){
				inSingleLineComment = 0;
			}
		}else if (inMultiLineComment == 1) {
			if (c == '*'){
				if ((d = getchar()) == '/'){
					inMultiLineComment = 0;
				}else {
					putchar(c);
					putchar(d);
				}
			}
		}else if (c == '/'){
			if ((d = getchar()) == '/'){
				inSingleLineComment = 1;
			}else if (d == '*'){
				inMultiLineComment = 1;
			}else {
				putchar(c);
				putchar(d);
			}
		}else {
			putchar(c);
		}
	}
}
