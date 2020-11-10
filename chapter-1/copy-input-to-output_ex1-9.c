#include <stdio.h>

int main()
{
	char c; 
	int blanks;
	
	while((c = getchar()) != EOF){
		if (c != ' '){
			putchar(c);
			blanks = 0;
		}else if (blanks == 0){
			putchar(c);
			blanks = 1;
		}
	}
}