/**
 * @file stack.h
 * @brief Entry header file to the library.
 *
 * @author Saurav Pal (resyfer)
 * @bug No known bugs
 */

#ifndef __LIBSTACK_H
#define __LIBSTACK_H

/* libc */
#include <sys/types.h>
#include <stdbool.h>

/**
 * @mainpage
 * A stack data structure to which elements of any data type can be pushed to
 * and popped from in a last in first out basis.
 */

/**
 * @brief Nodes in the stack.
 *
 * The building blocks of stack.
 */
typedef struct stack_node_t {
  void* value; /*!< Value stored in the node */
  struct stack_node_t *next; /*!< Next node in the linked list */
} stack_node_t;

/**
 * @brief Stack instance
 *
 * Implemented as a singly linked list, such that elements get pushed at head
 * as well as popped from it.
 */
typedef struct {
  u_int32_t size; /*!< Size of the stack */
  stack_node_t *head; /*!< Top of the stack */
} stack_t;

/**
 * @brief Initialize a stack
 *
 * @param stack A stack instance to initialize
 */
void stack_new(stack_t *stack);

/**
 * @brief Push an item to the stack
 *
 * @param stack Stack instance
 * @param value Value to push
 */
void stack_push(stack_t *stack, void* value);

/**
 * @brief Pop an item from the stack
 *
 * @param stack Stack instance
 * @return void* Popped element
 */
void* stack_pop(stack_t *stack);

/**
 * @brief Check if stack is empty
 *
 * @param stack Stack instance
 * @return true Stack is empty
 * @return false Stack is not empty
 */
bool stack_empty(stack_t *stack);

/**
 * @brief Peek the top-most element of stack
 *
 * @param stack Stack instance
 * @return void* Top most element
 */
void* stack_peek(stack_t *stack);

/**
 * @brief Free the stack's elements.
 *
 * @warning This does not free the stack data structure itself
 * 			but the elemental blocks it uses. Also it does not
 * 			free the elements added to the stack.
 *
 * @param stack Stack instance
 */
void stack_free(stack_t *stack);

#endif