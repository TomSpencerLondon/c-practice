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
	int inComment = 0;
	while((c = getchar()) != EOF) {
		if (inComment == 1 && c == '\n'){
			inComment = 0;
		}else if (c == '/'){
			if ((d = getchar()) == '/'){
				inComment = 1;
			}else {
				inComment = 0;
			}
		}else if (inComment == 0){
			putchar(c);
		}
	}
}