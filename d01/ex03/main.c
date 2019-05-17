#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/

	struct s_stack *stack = initStack();
	char message[256];
	int index = 0;

	for (int i = index; i < 256; i++)
		message[i] = '\0';

	while (1) {
		char *input = console();
		if (strcmp(input, "") == 0)
			continue;
		if (strcmp(input, "SEND") == 0) {
			printf("this message was sent: %s\n", message);
			break;
		}
		if (strcmp(input, "UNDO") == 0) {
			index = pop(stack);
			if (index >= 0) {
				for (int i = index; i < 256; i++)
					message[i] = '\0';
				printf("%s\n", message);
			}
			else {
				printf("Nothing to undo!\n");
				index = 0;
			}
		}
		else {
			push(stack, index);
			while (*input) {
				message[index] = *input;
				input++;
				index++;
			}
			printf("%s\n", message);
		}
	}

	return (0);
}



// Function used for the test
// Don't go further :)

