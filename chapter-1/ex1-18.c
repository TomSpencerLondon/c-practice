#include <stdio.h>
#define MAXLINE 1000
#define LONGLINE 80

int getLine(char line[], int maxline);
int removeSpaces(char line[]);

int main(){
	int len;
	
	char line[MAXLINE];
	
	while ((len = getLine(line, MAXLINE)) > 0){
		if (removeSpaces(line) > 0){
			printf("%s", line);
		}
	}
}


int removeSpaces(char line[]){
	int i, index;
	index = -1;
	
	for (i = 0; line[i] != '\0'; i++){
		if (line[i] != ' ' && line[i] != '\t'){
			index = i;
		}
	}
	
	line[index + 1] = '\0';
	return i;
}


/* getline: read a line into s, return length */
int getLine(char s[], int lim){
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
		s[i] = c;
	}
	
	s[i] = '\0';
	return i;
}