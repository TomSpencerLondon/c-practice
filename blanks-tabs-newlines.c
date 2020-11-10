#include <stdio.h>

int main() {
	char c;
	int blanks = 0;
	int tabs = 0;
	int newlines = 0;
	do {
		c = getchar();
		if (c == ' '){
		  blanks++;
		}else if (c == '\t'){
			tabs++;
		}else if(c == '\n'){
			newlines++;
		}
	}while(c != EOF);
	
	printf("Blanks = %u\n", blanks);
	printf("Tabs = %u\n", tabs);
	printf("Newlines = %u\n", newlines);
}