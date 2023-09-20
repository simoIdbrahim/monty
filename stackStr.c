#include "monty.h"

/**
 * print_char - function one
 * @stack: ptr arg one
 * @line_number: arg two
 * Return: void
 */

void print_char(stack_t **stack, unsigned int line_number)
{
	int asciiCode;

	if (stack == NULL || *stack == NULL)
	{
		string_err(11, line_number);
	}

	asciiCode = (*stack)->n;

	if (asciiCode < 0 || asciiCode > 127)
	{
		string_err(10, line_number);
	}
	printf("%c\n", asciiCode);
}

/**
 * print_str - fucntion two
 * @stack: arg one otr to ptr
 * @ln: arg two
 * Return: void
 */

void print_str(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
    int asciiCode;
    stack_t *tmp;

    if (stack == NULL || *stack == NULL)
    {
        printf("\n");
        return;
    }

    for (tmp = *stack; tmp != NULL; tmp = tmp->next)
    {
        asciiCode = tmp->n;
        if (asciiCode <= 0 || asciiCode > 127)
            break;
        printf("%c", asciiCode);
    }
    printf("\n");
}

/**
 * rotl - function three
 * @stack: arg one ptr to ptr
 * @ln: arg two
 * Return: void
 */

void rotl(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	
	for (tmp = *stack; tmp->next != NULL; tmp = tmp->next)
	{
		;
	}
	
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - function four
 * @stack: arg one ptr to ptr
 * @ln: arg two
 */

void rotr(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

    	tmp = *stack;
	
	for (; tmp->next != NULL; tmp = tmp->next);
	
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
