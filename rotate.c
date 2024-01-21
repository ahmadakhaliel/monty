#include "monty.h"

/**
 * rotate_first - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotate_first(stack_t **stack, unsigned int ln)
{
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    stack_t *tmp = *stack;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stack;
    (*stack)->prev = tmp;
    *stack = (*stack)->next;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
}


/**
 * rotate_last - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotate_last(stack_t **stack, unsigned int ln)
{
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    stack_t *tmp = *stack;

    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stack;
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    (*stack)->prev = tmp;
    (*stack) = tmp;
}

