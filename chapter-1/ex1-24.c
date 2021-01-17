// Write a program to check a C program for rudimentary syntax
// 	errors like unbalanced parentheses, brackets and braces.
// Don't forget about quotes, both single and double
// escape sequences, and comments.
// This program is hard if you do it in full generality.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// Good
// 2 + (3 + 8)
// Bad
// 9 + (3
// 2) - 7 + (10 / 5)

// startLoop to get characters
// balanced = 0
// if char == '(' balanced += 1
// if char == ')' balanced -= 1
//   if balanced < 0 stop loop
// endLoop
// if balanced == 0 print: "Balanced expression"
// else print: "Unbalanced expression"



#define IN_QUOTATION 3
#define IN_MULTI_LINE_COMMENT 2
#define IN_SINGLE_LINE_COMMENT 1
#define NOT_IN_COMMENT_OR_QUOTATION 0
void checkParentheses(int);

int state;
int c;
int d;
int parenthesisCounter = 0;
int bracketsCounter = 0;
int bracesCounter = 0;

void processInSingleLine(int c){
	if (c == '\n'){
		state = NOT_IN_COMMENT_OR_QUOTATION;
	}	
}

void processInMultiLine(int c){
	if (c == '*'){
		if ((d = getchar()) == '/'){
			state = NOT_IN_COMMENT_OR_QUOTATION;
		}
	}
}

void processNotInCommentOrQuotation(int c){
	if (c == '"'){
		state = IN_QUOTATION;
	}else if (c == '/'){
		if ((d = getchar()) == '/'){
			state = IN_SINGLE_LINE_COMMENT;
		}else if (d == '*'){
			state = IN_MULTI_LINE_COMMENT;
		}
	}else {
		checkParentheses(c);
	}
}

void checkParentheses(int c){
	if(c == '('){
		parenthesisCounter++;
	}else if (c == ')'){
		if (parenthesisCounter == 0){
			printf("Error unbalanced expression");
			exit(EXIT_FAILURE);
		}
		parenthesisCounter--;
	}else if (c == '['){
		bracketsCounter++;
	}else if (c == ']'){
		if (bracketsCounter == 0){
			printf("Error unbalanced expression");
			exit(EXIT_FAILURE);
		}
		bracketsCounter--;
	}else if (c == '{'){
		bracesCounter++;
	}else if (c == '}'){
		if (bracesCounter == 0){
			printf("Error unbalanced expression");
			exit(EXIT_FAILURE);
		}
		bracesCounter--;
	}
}

void processInQuotation(int c){
	if (c == '"'){
		state = NOT_IN_COMMENT_OR_QUOTATION;
	}
}

int main(){
	state = NOT_IN_COMMENT_OR_QUOTATION;
	
	while((c = getchar()) != EOF) {
		switch(state)
		{
			case IN_QUOTATION:
				processInQuotation(c);
				break;
			case IN_SINGLE_LINE_COMMENT:
				processInSingleLine(c);
				break;
			case IN_MULTI_LINE_COMMENT:
				processInMultiLine(c);
				break;
			case NOT_IN_COMMENT_OR_QUOTATION:
				processNotInCommentOrQuotation(c);
		}
	}

	if (parenthesisCounter == 0 && bracketsCounter == 0 && bracesCounter == 0){
		printf("Balanced expression");
	}else {
		printf("Unbalanced expression");
		exit(EXIT_FAILURE);
	}
}
