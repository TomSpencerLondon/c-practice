#include <stdio.h>

int main(int argc, char *argv[]){
	int c = 1;
	while(c < argc){
		printf("%s\n", argv[c++]);
	}
	
	
	return 0;
}




// #include <stdio.h>
// #include <getopt.h>
// #include <stdlib.h>
//
// /*
// print Fahrenheit-Celsius table
// for farh = 0, 20, ..., 300
// */
//
// int main(int argc, char *argv[]) {
// 	float fahr, celsius;
// 	float lower, upper, step;
//
// 	if (argc > 1) {
//
// 		upper = atof(argv[2]);
// 		step = atof(argv[3]);
// 	}
//
//
//
// 	lower = 0.0;
// 	// upper = 300.0;
// 	// step = 20.0;
//
// 	fahr = lower;
// 	printf("\t  %c\t   %c\n", 'F', 'C');
// 	while (fahr <= upper) {
// 		celsius = (5.0 / 9.0) * (fahr - 32.0);
// 		printf("\t%3.0f\t%6.1f\n", fahr, celsius);
// 		fahr = fahr + step;
// 	}
//
// 	return 0;
// }
