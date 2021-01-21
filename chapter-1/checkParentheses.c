#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char stack[80];
int stackPosition = 0;

bool isMatchingPair(char character1, char character2){ 
    if (character1 == '(' && character2 == ')'){
    	return 1; 
    }else if (character1 == '{' && character2 == '}'){
    	return 1;
    }else if (character1 == '[' && character2 == ']'){
    	return 1; 
    }else{
			putchar(character1);
			putchar('\n');
			putchar(character2);
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


void checkParentheses(int c){
	if(c == '(' || c == '{' || c == '['){
		stack[++stackPosition] = c;
	}else if (c == ')' || c == '}' || c == ']'){
		if(isMatchingPair(stack[stackPosition], c) == 0){
			printf("Error unbalanced expression.");
			exit(EXIT_FAILURE);
		}
	}
}


int main(){
	int c;
	while((c = getchar()) != EOF) {
		checkParentheses(c);
	}
	
	for (int i = 0; i < 80; i++){
		if (stack[i] != '\0'){
			printf("Unbalanced expression");
			exit(EXIT_FAILURE);
		}
	}
	
	printf("Balanced expression");
}
