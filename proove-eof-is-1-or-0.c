#include <stdio.h>

int main() {
	int c;
	printf("%c is EOF.", EOF);
	do {
		c = getchar();
		if ((c == EOF) == 1){
			printf("This is inside EOF");
		}else if ((c == EOF) == 0){
			printf("this is inside EOF = 0");
		}else {
			printf("SOMETHING ELSE!!!!");
		}
	} while (c != EOF);
	
	return 0;
}