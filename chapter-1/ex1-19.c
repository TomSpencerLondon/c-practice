#include <stdio.h>
#define MAXLINE 1000
#define LONGLINE 80

int getLine(char line[], int maxline);
int reverseLine(char line[], char reverse[], int len);

int main(){
	int len;
	
	char line[MAXLINE];
	char reversed[MAXLINE];
	
	while ((len = getLine(line, MAXLINE)) > 0){
		reverseLine(line, reversed, len);
		printf("%s", reversed);
	}
}


int reverseLine(char line[], char reverse[], int len){
	int i;
	int end;
	end = len - 1;
	
	for (i = 0; i < len; i++){
		reverse[i] = line[end];
		end--;
	}
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