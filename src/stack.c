#include <include/stack.h>
#include <stdlib.h>

void
stack_new(stack_t *stack)
{
	stack->head = NULL;
	stack->size = 0;
}

bool
stack_empty(stack_t *stack)
{
	return stack->size == 0;
}

void
stack_push(stack_t *stack, void* value)
{
	stack_node_t *node = malloc(sizeof(stack_node_t));
	node->value = value;
	node->next = stack->head;

	stack->head = node;
	stack->size++;
}

void*
stack_pop(stack_t *stack)
{
	if(stack_empty(stack)) {
		return NULL;
	}

	stack_node_t *temp = stack->head;
	void* value = temp->value;
	stack->head = stack->head->next;

	free(temp);
	stack->size--;
	return value;
}

void*
stack_peek(stack_t *stack)
{
	if(stack->size == 0) {
		return NULL;
	}

	return stack->head->value;
}

void
stack_free(stack_t *stack)
{
	stack_node_t *temp = stack->head;
	while(temp) {
		stack_node_t *temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
}
