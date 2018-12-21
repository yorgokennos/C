/* Yorgo Kennos
   December 1st, 2018
   Advent Of Code Day 1
   Link: https://adventofcode.com/2018/day/1


*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

	FILE * frequency;

	signed int number = 0, counter = 0;

	if ((frequency = fopen("frequency.txt", "r")) == NULL) {
		printf("Error opening file!\n");
		exit(1);
	}

	for (int i = 0; i < 989; i++) {
			fscanf(frequency, "%d", &number);
			printf("Curren frequency %d, ", counter);
			counter += number;
			printf("change of %d; resulting frequency %d\n", number, counter);

	}
	


	return 0;
}
