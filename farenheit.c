#include <stdio.h>

/*
print Fahrenheit-Celsius table
for farh = 0, 20, ..., 300
*/

int main() {
	float fahr, celsius;
	
	float lower, upper, step;
	
	lower = 0.0;
	upper = 300.0;
	step = 20.0;
	
	fahr = lower;
	printf("\t  %c\t   %c\n", 'F', 'C');
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("\t%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	return 0;
}