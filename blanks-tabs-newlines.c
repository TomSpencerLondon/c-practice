#include <stdio.h>

int main() {
	char c;
	int count = 0;
	do {
		c = getchar();
		if ((c != '\n') && (c != EOF)){
		  count++;
		}
	}while(c != EOF);
	
	printf("Characters = %u", count);
}