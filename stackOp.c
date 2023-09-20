#include "monty.h"

/**
 * mul_nodes - function one
 * @stack: pointer arg one
 * @line_number: arg two
 * Return: void
 */

void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int calc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		more_err(8, line_number, "mul");
	}

	(*stack) = (*stack)->next;
	calc = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = calc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - function two
 * @stack: pointer arg one
 * @line_number: arg two
 * Return: void
 */

void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int calc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		more_err(8, line_number, "mod");
	}


	if ((*stack)->n == 0)
	{
		more_err(9, line_number);
	}

	(*stack) = (*stack)->next;
	calc = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = calc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
