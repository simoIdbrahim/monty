#include "monty.h"
stack_t *head = NULL;

/**
 * main - function one
 * @argc: arg one
 * @argv: arg two
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - function two
 * @n: arg two
 * Return: node
 */

stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		err(4);
	}

	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - function three
 * Return: void
 */

void free_nodes(void)
{
	stack_t *tmp;
	
	for (tmp = head; tmp != NULL;)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}

/**
 * add_to_queue - function four
 * @new_node: arg one
 * @ln: arg two
 * Return: void
 */

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
