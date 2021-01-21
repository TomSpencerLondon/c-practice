// Write a program to check a C program for rudimentary syntax
// 	errors like unbalanced parentheses, brackets and braces.
// Don't forget about quotes, both single and double
// escape sequences, and comments.
// This program is hard if you do it in full generality.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
int lineNumber = 1;
char stack[80];
int stackPosition = 0;

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
		if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}'){
			checkParentheses(c);
		}
	}
}

void isBalanced(int counter){
	if (counter < 0){
		printf("Error unbalanced expression. Line:  %d", lineNumber);
		exit(EXIT_FAILURE);
	}
}

bool isMatchingPair(char character1, char character2){ 
    if (character1 == '(' && character2 == ')'){
    	return 1; 
    }else if (character1 == '{' && character2 == '}'){
    	return 1;
    }else if (character1 == '[' && character2 == ']'){
    	return 1; 
    }else{
    	return 0;
    }
}


// Extra challenge: check that multiple variants of brackets are balanced 
// Not balanced
// ([)]
// Not balanced
// [(])

// Balanced
// [()]{[()()]()}

// Balanced
// [({})([])()]{[(){}]}
      // |
// [()]
//
// {'[', }
// 0

void checkParentheses(int c){
	if(c == '(' || c == '{' || c == '['){
		stack[stackPosition] = c;
		stackPosition++;
	}else if (c == ')' || c == '}' || c == ']'){
		stackPosition = stackPosition - 1;
		bool isMatching = isMatchingPair(stack[stackPosition], c);
		if(isMatching == 0){
			printf("Error unbalanced expression. Line:  %d", lineNumber);
			exit(EXIT_FAILURE);
		}else {
			stack[stackPosition] = '\0';
		}
	}
}

void processInQuotation(int c){
	if (c == '"'){
		state = NOT_IN_COMMENT_OR_QUOTATION;
	}
}

void incrementLine(int c){
	if(c == '\n'){
		lineNumber++;
	}
}

int main(){
	state = NOT_IN_COMMENT_OR_QUOTATION;
	
	while((c = getchar()) != EOF) {
		incrementLine(c);
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
	
	for (int i = 0; i < 80; i++){
		if (stack[i] != '\0'){
			printf("Unbalanced expression");
			exit(EXIT_FAILURE);
		}
	}
	
	printf("Balanced expression");
}
