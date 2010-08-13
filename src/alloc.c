/*
** alloc.c
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/
#include <stdio.h>
#include <stdlib.h>

void	*xmalloc(size_t size, char *msg)
{
	void *ptr;

	if ((ptr = malloc(size)) == NULL)
		{
			fprintf(stderr, "%s\n", msg);
			exit(EXIT_FAILURE);
		}
	return (ptr);
}

void	*xrealloc(void *ptr, size_t size)
{
	if ((ptr = realloc(ptr, size)) == NULL)
		{
			fprintf(stderr, "Virtual memory exhausted\n");
			exit(EXIT_FAILURE);
		}
	return (ptr);
}

