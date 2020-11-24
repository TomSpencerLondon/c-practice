#include <stdio.h>

#define LOWER 0.0
#define UPPER 300.0
#define STEP 20.0

float celsius(float farh);

int main() {
	float fahr;
	
	printf("\t  %c\t   %c\n", 'F', 'C');
	for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
		printf("\t%3.0f\t%6.1f\n", fahr, celsius(fahr));
	}
	
	return 0;
}

float celsius(float fahr){
	float celsius = (5.0 / 9.0) * (fahr - 32.0);
	return celsius;
}