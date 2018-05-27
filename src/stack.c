/*
 ============================================================================
 Name        : stack.c
 Author      : eduardo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


// Simpler implementation cuz the same elemement that you put in the
// the stack is the one that pop out


#define STACKSIZE 5

typedef struct stackitem {
	int data;
} STACKITEM;

STACKITEM *top;
STACKITEM *end;
STACKITEM *base;

// why can't I use these vars in here?
// just define them.

void push(STACKITEM *item) {
	memcpy(top, item, sizeof(STACKITEM));
	top++;
}

int main(void) {
	base = (STACKITEM *) malloc(STACKSIZE * sizeof(STACKITEM));
	top = base;

	STACKITEM item1;
	item1.data = 1;
	push(&item1);

	STACKITEM item2;
	item2.data = 2;
	push(&item2);

	STACKITEM *q = base;

	while (q != top) {
		printf("item number %d\n", q->data);
		q++;
	}

	return EXIT_SUCCESS;
}
