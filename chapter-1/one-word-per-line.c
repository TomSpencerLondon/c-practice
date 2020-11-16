# include <stdio.h>

# define IN 1
# define OUT 0

int main() {
	int character, state;
	
	state = OUT;
	
	while ((character = getchar()) != EOF){
		if ((character == ' ' || character == '\n' || character == '\t') && (state == IN)){
				putchar('\n');
				state = OUT;
		}else if (state == OUT){
			putchar(character);
			state = IN;
		}else if (state == IN) {
			putchar(character);
		}
	}
}