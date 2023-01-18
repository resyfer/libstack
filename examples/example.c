#include <libstack/stack.h>
#include <stdio.h>

int main() {

	/* Initialize stack */
	stack_t s;
	stack_new(&s);

	/* Push an element to the stack */
	int a = 10;
	stack_push(&s, (void*) &a);

	char b = 'a';
	stack_push(&s, (void*) &b);

	/* Pop elements from the stack */
	printf("%c\n", *((char*) stack_pop(&s)));
	printf("%d\n", *((int*) stack_pop(&s)));

	return 0;
}