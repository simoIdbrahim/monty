#include "monty.h"

/**
 * add_to_stack - function one
 * @new_node: arg one ptr to ptr
 * @ln: arg two
 * Return: void
 */

void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_stack - function two
 * @stack: arg one ptr to ptr
 * @line_number: arg two
 * Return: void
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	
	(void)line_number;
	
	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	tmp = *stack;
	for (; tmp != NULL; tmp = tmp->next)
	{
		printf("%d\n", tmp->n);
	}
}

/**
 * pop_top - function three
 * @stack: arg one ptr to ptr
 * @line_number: arg two
 * Return: void
 */

void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		more_err(7, line_number);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(tmp);
}

/**
 * print_top - function four
 * @stack: arg one
 * @line_number: arg two
 * Return: void
 */

void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		more_err(6, line_number);
	}
	printf("%d\n", (*stack)->n);
}
