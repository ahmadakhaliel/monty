#include "monty.h"

/**
 * add_to_stack - adds a node to the stack.
 * @new_node: Pointer 
 * @ln: Interger representing the line number.
 */
void add_to_stack(stack_t **new_node, unsigned int ln)
{
    
    if (new_node == NULL || *new_node == NULL) 
    {
        fprintf(stderr, "Error at line %u: Invalid new_node\n", ln);
        exit(EXIT_FAILURE);
    }
    if (head == NULL) 
    {
        head = *new_node;
        return;
    }
    stack_t *tmp = head;
    head = *new_node;
    head->next = tmp;
    tmp->prev = head;
}
