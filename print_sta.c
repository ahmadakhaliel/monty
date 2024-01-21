#include "monty.h"

/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *current_node;

    (void)line_number;

    if (stack == NULL)
    {
        printf(stderr, "Error: NULL stack pointer\n");
        exit(EXIT_FAILURE);
    }
    current_node = *stack;
    while (current_node != NULL)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}
