#include "monty.h"

stack_t *stk_tp = NULL;
/**
 * main - the enrty point of the monty program.
 * @ac: the num of args passed tot the main prog.
 * @av: pointer to the array of the arguments.
 * Return: zzeroo.
*/
int main(int ac, char *av[])
{
	FILE *user_f;
	char *thebuff;
	size_t buffsz;
	unsigned int line_nm = 1;

	if (ac == 1 || ac > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	user_f = fopen(av[1], "r");
	if (user_f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&thebuff, &buffsz, user_f) != -1)
	{
		gt_cmnd(thebuff, line_nm);
		line_nm++;
	}
	free(thebuff);
	fclose(user_f);
	fre_it();
	return (0);
}
/**
 * gt_cmnd - a function that i used to get two things,
 * the command (opcode) and the value entered by the users.
 * @thebuff: pointer to the buffer that contains the specific
 * line that holds the opcode andthe value.
 * @line_nm: the bumber of the line in which the opcode is included.
 * Return : nothing.
*/
void gt_cmnd(char *thebuff, unsigned int line_nm)
{
	char *command;
	char *the_val;
	const char *thedel;
	int dn = 0, idx = 0;
	instruction_t op_a_func[] = {
		{"push", ad_to_stk},
		{"pall", prnt_stk},
		{NULL, NULL}
	};

	if (thebuff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	thedel = "\n $";
	command = strtok(thebuff, thedel);
	the_val = strtok(NULL, thedel);
	while (op_a_func[idx].opcode != NULL)
	{
		if (strcmp(op_a_func[idx].opcode, command) == 0)
		{
			is_push(op_a_func[idx].f, command, the_val, line_nm);
			dn = 1;
		}
		idx++;
	}
	if (dn == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_nm, command);
		exit(EXIT_FAILURE);
	}
}
/**
 * is_push - a function to call the push function if the command is push
 * or if the command was not push, it will call the required function.
 * @cal_it: the fucntion passed.
 * @command: the writted command.
 * @the_val: the written value.
 * @line_nm: the line number where the command was written.
 * Return: void.
*/
void is_push(req_func cal_it, char *command,
		char *the_val, unsigned int line_nm)
{
	stack_t *holder_n = NULL;

	if (strcmp(command, "push") == 0)
	{
		if (the_val == NULL || isdigit(*the_val) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_nm);
			exit(EXIT_FAILURE);
		}
		holder_n = make_nd(atoi(the_val));
		cal_it(&holder_n, line_nm);
	}
	else
		cal_it(&stk_tp, line_nm);
}
/**
 * prnt_stk - a fucntion to print the values in the stack.
 * @stk_tp: pointer to the top of the stack.
 * @line_nm: the number og the line where the command exists.
 * Return: nothing.
*/
void prnt_stk(stack_t **stk_tp, unsigned int line_nm)
{
	stack_t *tracking_s = NULL;

	(void) line_nm;
	if (stk_tp == NULL)
		exit(EXIT_FAILURE);
	tracking_s = *stk_tp;
	while (tracking_s != NULL)
	{
		printf("%d\n", tracking_s->n);
		tracking_s = tracking_s->next;
	}
}
/**
 * make_nd - a function to malloc a node and insert the value.
 * @val: the value to be inserted in the node.
 * Return: pointer to the new node.
*/
stack_t *make_nd(int val)
{
	stack_t *nw_nd = NULL;

	nw_nd = malloc(sizeof(stack_t));
	if (nw_nd == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	nw_nd->n = val;
	nw_nd->prev = NULL;
	nw_nd->next = NULL;
	return (nw_nd);
}
