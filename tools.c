#include "monty.h"

/**
 * open_file - function one
 * @file_name: arg one
 * Return: void
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		err(2, file_name);
	}

	read_file(fd);
	fclose(fd);
}

/**
 * read_file - function two
 * @fd: arg one
 * Return: void
 */

void read_file(FILE *fd)
{
	int number, frm = 0;
	char *buf = NULL;
	size_t length = 0;

	for (number = 1; getline(&buf, &length, fd) != -1; number++)
		frm = parse_line(buf, number, frm);

	free(buf);
}

/**
 * parse_line - function three
 * @buffer: arg one
 * @line_number: arg two
 * @format: arg three
 * Return: 0 || 1.s
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *oc;
  	char *val;
	const char *brLin = "\n ";

	if (buffer == NULL)
	{
		err(4);
	}

	oc = strtok(buffer, brLin);

	if (oc == NULL)
	{
		return (format);
	}

	val = strtok(NULL, brLin);

	if (strcmp(oc, "stack") == 0)
	{
		return (0);
	}
	if (strcmp(oc, "queue") == 0)
	{
		return (1);
	}

	find_func(oc, val, line_number, format);
	return (format);
}

/**
 * find_func - function four
 * @opcode: arg one
 * @value: arg two
 * @format: arg three
 * @ln: agr four
 * Return: void
 */

void find_func(char *opcode, char *value, int ln, int format)
{
	int index;
	int f;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (f = 1, index = 0; func_list[index].opcode != NULL; index++)
	{
		if (strcmp(opcode, func_list[index].opcode) == 0)
		{
			call_fun(func_list[index].f, opcode, value, ln, format);
			f = 0;
		}
	}
	if (f == 1)
	{
		err(3, ln, opcode);
	}
}

/**
 * call_fun - function five
 * @func: arg one
 * @op: arg two
 * @val: arg three
 * @ln: arg four
 * @format: arg five
 */

void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int f;
	int ind;

	f = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			f = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (ind = 0; val[ind] != '\0'; ind++)
		{
			if (isdigit(val[ind]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * f);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
	{
		func(&head, ln);
	}
}
