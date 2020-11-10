#include <stdio.h>

int main()
{
	char c;
	
	while((c = getchar()) != EOF){
		if (c == '^'){
			printf("Hello");
		}
		
		// if (c == '\t'){
// 			printf("\\t");
// 		}else if (c =='\r'){
// 			printf("hello");
// 		}else if (c == '\\'){
// 			printf("\\\\");
// 		}else {
// 			putchar(c);
// 		}
	}
}