#include <stdio.h>
#define MAXLINE 1000
#define LONGLINE 80

int getLine(char line[], int maxline);

int main(){
	int len;
	
	char line[MAXLINE];
	
	while ((len = getLine(line, MAXLINE)) > 0){
		if ( len > 0){
			printf("%s", line);
		}
	}
}


/* getline: read a line into s, return length */
int getLine(char s[], int lim){
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
		printf("This is c in the loop: %d", c);
		s[i] = c;
	}
	
	printf("This is c: %d\n", c);
	
	if (c == 'd'){
		printf("This is D: %d", c);
		s[i] = 'l';
	}

	if (c == '\n'){
		s[i] = c;
		++i;
	}
	
	s[i] = '\0';
	return i;
}