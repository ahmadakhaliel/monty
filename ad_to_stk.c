#include "monty.h"
/**
 * ad_to_stk - a function to add a node to the stack.
 * @nw_pt: pointer to the newly created node.
 * @line_nm: the number of the line which contains the command.
 * Return: void.
*/
void ad_to_stk(stack_t **nw_pt, unsigned int line_nm)
{
	(void) line_nm;
	if (nw_pt == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (stk_tp == NULL)
	{
		stk_tp = *nw_pt;
		return;
	}
	(*nw_pt)->next = stk_tp;
	stk_tp->prev = *nw_pt;
	stk_tp = *nw_pt;
}
