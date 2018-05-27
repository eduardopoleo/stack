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


#define STACKSIZE 3

typedef struct stackitem {
	int data;
} STACKITEM;

STACKITEM *top;
STACKITEM *end;
STACKITEM *base;

// why can't I use these vars in here?
// just define them.

void push(STACKITEM *item) {
	if (top == end) {
		printf("The stack is at full capacity\n");
		return;
	}

	memcpy(top, item, sizeof(STACKITEM));
	top++;
}

STACKITEM pop() {
	if (top == end) {
		printf("The stack is empty nothing to pop\n");
		STACKITEM item;
		return item;
	}

	top--;
	STACKITEM item = *(top);
	printf("Popping item with value %d\n", item.data);
	return item;
}

int main(void) {
	// For pushing it seems that it does not matter whether or not
	// you go over the stack.
	//	This is dangerous cuz we might be overriding other important
	//	part of memory allocated for other purposes.

	base = (STACKITEM *) malloc(STACKSIZE * sizeof(STACKITEM));
	end = base + STACKSIZE;
	top = base;

	for (int i = 0; i < 4; i++) {
		STACKITEM item;
		item.data = i;
		push(&item);
	}

	STACKITEM *q = base;

	while (q != top) {
		printf("item number %d\n", q->data);
		q++;
	}

	return EXIT_SUCCESS;
}
