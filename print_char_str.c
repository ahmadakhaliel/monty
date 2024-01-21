#include "monty.h"

/**
 * print_char - Prints the ASCII
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number) 
{
    if (stack == NULL || *stack == NULL) 
    {
        string_err(11, line_number);
    }
    int ascii = (*stack)->n;
    if (ascii < 0 || ascii > 127) 
    {
        string_err(10, line_number);
    }
    printf("%c\n", (char)ascii);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **stack, unsigned int ln) 
{
    if (stack == NULL || *stack == NULL) 
    {
        printf("\n");
        return;
    }
    stack_t *tmp = *stack;

    while (tmp != NULL) 
    {
        int ascii = tmp->n;
        if (ascii <= 0 || ascii > 127) 
        {
            break;
        }
        printf("%c", (char)ascii);
        tmp = tmp->next;
    }
    printf("\n");
}
