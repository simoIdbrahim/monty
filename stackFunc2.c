#include "monty.h"

/**
 * nop - function one
 * @stack: arg one
 * @line_number: arg two
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_nodes - function two
 * @stack: arg one
 * @linee_number: arg two
 * Return: void
 */

void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		more_err(8, line_number, "swap");
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)
	{
		tmp->next->prev = *stack;
	}

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - fucntion three
 * @stack: arg one
 * @line_number: arg two
 * Return: void
 */

void add_nodes(stack_t **stack, unsigned int line_number)
{
	int calc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		more_err(8, line_number, "add");
	}

	(*stack) = (*stack)->next;
	calc = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = calc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - function four
 * @stack: arg one ptr
 * @line_number: arg two
 * Return: void
 */

void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int calc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		more_err(8, line_number, "sub");
	}

	(*stack) = (*stack)->next;
	calc = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = calc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - function five
 * @stack: arg one
 * @line_number: arg two
 * Return: void
 */

void div_nodes(stack_t **stack, unsigned int line_number)
{
	int calc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		more_err(8, line_number, "div");
	}

	if ((*stack)->n == 0)
	{
		more_err(9, line_number);
	}

	(*stack) = (*stack)->next;
	calc = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = calc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
