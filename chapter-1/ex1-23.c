// Write a program to remove all comments
// from a C program
// Don't forget to handle quoted strings and character constants
// properly. C comments do not nest
#include <string.h>
#include <stdio.h>
// the house 
// on the
// prairie

#define IN_QUOTATION 3
#define IN_MULTI_LINE_COMMENT 2
#define IN_SINGLE_LINE_COMMENT 1
#define NOT_IN_COMMENT_OR_QUOTATION 0

int state;
int c;
int d;

void processInSingleLine(int c){
	if (c == '\n'){
		state = NOT_IN_COMMENT_OR_QUOTATION;
	}	
}

void processInMultiLine(int c){
	if (c == '*'){
		if ((d = getchar()) == '/'){
			state = NOT_IN_COMMENT_OR_QUOTATION;
		}else {
			putchar(c);
			putchar(d);
		}
	}
}

void processNotInCommentOrQuotation(int c){
	if (c == '"'){
		state = IN_QUOTATION;
		putchar(c);
	}else if (c == '/'){
		if ((d = getchar()) == '/'){
			state = IN_SINGLE_LINE_COMMENT;
		}else if (d == '*'){
			state = IN_MULTI_LINE_COMMENT;
		}else {
			putchar(c);
			putchar(d);
		}
	}else {
		putchar(c);
	}
}

void processInQuotation(int c){
	if (c == '"'){
		state = NOT_IN_COMMENT_OR_QUOTATION;
	}
	putchar(c);
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
}
