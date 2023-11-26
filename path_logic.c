#include "shell.h"


/**
 * add_node - adds node at the beginning of lst_path
 * @head: head
 * @path: path
 * Return: new node address
*/
lst_path *add_node_to_linkedlst(lst_path **head, char *path)
{
	char *path_copy;
	int n = 0;
	lst_path *node;

	/* Calculate length of path string */
	while (path[n] != '\0')
		n++;

	/* Allocate memory for the new node */
	node = malloc(sizeof(lst_path));

	if (node == NULL)
		return (NULL);

	if (path)
	{
		/* Duplicate the path string */
		path_copy = _strdup(path);
		if (path_copy == NULL)
		{
			free(node);
			return (NULL);
		}
		/* Set length and path of new node */
		node->length = n;
		node->path = path_copy;
	}
	/* If path is NULL, set length to 0 and path to NULL */
	else
	{
		node->length = 0;
		node->path = NULL;
	}
	/* insert new node at the beginning of linked list */
	node->next = (*head);
	*head = node;

	return (node);
}


/**
 * convert_paths_to_linkedlist - paths linked list tokenized
 * from PATH environment variable
 * Return: paths in PATH environment variable
*/
lst_path *convert_paths_to_linkedlist()
{
	lst_path *paths;
	char *token, *path_env_var, *paths_copy;

	paths = NULL;
	/* Get the PATH environment variable */
	path_env_var = _get_env_value("PATH");
	if (path_env_var == NULL)
		return (NULL);

	/* Duplicate PATH environment var to avoid modification */
	paths_copy = _strdup(path_env_var);
	if (paths_copy == NULL)
		return (NULL);
	/* Tokenize the duplicated PATH str using ':' as delimiter */
	token = strtok(paths_copy, ":");
	while (token != NULL)
	{
		/* Add each path token to linked list */
		add_node_to_linkedlst(&paths, token);
		token = strtok(NULL, ":");
	}
	/* Free duplicated PATH string */
	free(paths_copy);

	return (paths);
}

/**
 * print_linkedlist - print lst_path elements
 * @head: head
 * Return: no.of nodes
*/
size_t print_linkedlist(const lst_path *head)
{
	int num;
	/* If linked list is empty, return 0 */
	if (head == NULL)
		return (0);

	num = 0;

	/*  Iterate through the linked list */
	while (head)
	{
		if (head->path == NULL)
		{
			printf("[0] (nil)\n");
			fflush(stdout);
		}
		else
		{
			/* Print length and path of the current node */
			printf("[%d] %s\n", head->length, head->path);
			fflush(stdout);
		}

		head = head->next;/*  Move to the next node in the linked list */
		num++;/* Increment node count */
	}

	return (num);
}
