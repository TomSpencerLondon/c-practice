#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

/*
print Fahrenheit-Celsius table
for farh = 0, 20, ..., 300
*/

int main(int argc, char *argv[]) {
	// upper = 300.0;
	// step = 20.0;
	
	fahr = lower;
	printf("\t  %c\t   %c\n", 'F', 'C');
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("\t%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	return 0;
}

// int main(int argc, char *argv[]) {
//     int opt;
//     options_t options = { 0, 0x0, stdin, stdout };
//
//     opterr = 0;
//
//     while ((opt = getopt(argc, argv, OPTSTR)) != EOF)
//        switch(opt) {
//            case 'i':
//               if (!(options.input = fopen(optarg, "r")) ){
//                  perror(ERR_FOPEN_INPUT);
//                  exit(EXIT_FAILURE);
//                  /* NOTREACHED */
//               }
//               break;
//
//            case 'o':
//               if (!(options.output = fopen(optarg, "w"))