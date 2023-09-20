#include "monty.h"

/**
 * err - function one
 * @error_code: one arg
*/

void err(int error_code, ...)
{
	va_list ag;
	char *zaba;
	int number;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			number = va_arg(ag, int);
			zaba = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", number, zaba);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}

	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - function two
 * @error_code: one arg
*/

void more_err(int error_code, ...)
{
	va_list ag;
	char *zaba;
	int number;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			number = va_arg(ag, unsigned int);
			zaba = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", number, zaba);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
  
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - function three
 * @error_code: one arg
*/

void string_err(int error_code, ...)
{
	va_list ag;
	int number;

	va_start(ag, error_code);
	number = va_arg(ag, int);

	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
			break;
		default:
			break;
	}

	free_nodes();
	exit(EXIT_FAILURE);
}
