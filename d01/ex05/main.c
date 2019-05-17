#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();
	/*-------------------
	launch your test here
	--------------------*/
	for (int i = 0; i < 30; i++)
		tankPush(tank, 70 + i);
	printf("Pushing 70 + i, 30 times into tank\n");
	printf("Number of stacks: %i\n", tank->n);
	printf("Sum in second stack: %i\n", tank->stacks[1]->sum);
	for (int i = 0; i < 20; i++)
		printf("Popping tank %i\n", tankPop(tank));
	printf("Number of stacks: %i\n", tank->n);
	printf("Attempting to push 200 energy in...\n");
	tankPush(tank, 200);
	return (0);
}



// Function used for the test
// Don't go further :)
