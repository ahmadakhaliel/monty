#include "monty.h"

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the linenumb
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
    stack_t *top_node;

    if (stack == NULL || *stack == NULL)
    {
        more_err(7, line_number);
    }
    top_node = *stack;
    *stack = top_node->next;
    if (*stack != NULL)
    {
        (*stack)->prev = NULL;
    }
    free(top_node);
}

