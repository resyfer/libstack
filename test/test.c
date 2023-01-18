#include <stdio.h>
#include <libstack/stack.h>
#include <assert.h>

void crud_test() {
	printf("\n!!--CRUD Test--!!\n");

	stack_t s;
	stack_new(&s);

	printf("✅ Stack initialization\n");

	assert(stack_empty(&s));

	printf("✅ Stack Empty\n");

	int a = 10, b = 15;

	stack_push(&s, (void*) &a);
	assert(s.size == 1);

	printf("✅ Stack Push\n");

	stack_push(&s, (void*) &b);
	assert(s.size == 2);

	assert(*((int*)stack_peek(&s)) == b);

	printf("✅ Stack Peek\n");

	assert(*((int*)stack_pop(&s)) == b);
	assert(*((int*)stack_peek(&s)) == a);
	assert(s.size == 1);

	printf("✅ Stack Pop\n");

	stack_free(&s);

	printf("✅ Stack Free\n");
}

int main() {
	crud_test();
	return 0;
}