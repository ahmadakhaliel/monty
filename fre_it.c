#include "monty.h"
/**
 * fre_it - a function to free each node after the program is executed
 * or if it encounters an error.
*/
void fre_it(void)
{
	stack_t *holder;

	while (stk_tp != NULL)
	{
		holder = stk_tp;
		stk_tp = stk_tp->next;
		free(holder);
	}
}
