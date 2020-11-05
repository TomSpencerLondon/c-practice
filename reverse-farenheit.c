#include <stdio.h>

/*
print Fahrenheit-Celsius table
for farh = 0, 20, ..., 300
*/

#define LOWER 0.0
#define UPPER 300.0
#define STEP 20.0

int main() {
	float fahr, celsius;
	
	printf("\t  %c\t   %c\n", 'F', 'C');
	for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("\t%3.0f\t%6.1f\n", fahr, celsius);
	}
	
	return 0;
}