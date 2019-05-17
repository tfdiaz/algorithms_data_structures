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
	char *a = "A";
	char *b = "B";
	char *c = "C";
	char *d = "D";

	struct s_queue *queue = queueInit();
	printf("Enqueing %s\n", a);
	enqueue(queue, a);
	printf("Enqueing %s\n", b);
	enqueue(queue, b);
	printf("Enqueing %s\n", c);
	enqueue(queue, c);
	printf("Enqueing %s\n", d);
	enqueue(queue, d);
	printf("Is Queue Empty == 1: %i\n", isEmpty(queue));
	printf("Peek: %s\n", peek(queue));
	printf("Dequeue: %s\n", dequeue(queue));
	printf("Dequeue: %s\n", dequeue(queue));
	printf("Dequeue: %s\n", dequeue(queue));
	printf("Dequeue: %s\n", dequeue(queue));
	printf("Dequeue: %s\n", dequeue(queue));
	printf("Is Queue Empty == 1: %i\n", isEmpty(queue));
	free(queue);
	return (0);
}



// Function used for the test
// Don't go further :)

