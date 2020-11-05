#include <stdio.h>

/* copy input to output; 2nd version */
int main(){
	int c;
  do {
	  c = getchar() != EOF;
	  putchar(c);
	} while (c != 1);
}
