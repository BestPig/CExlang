/*
** segment.c
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/
#include <stdio.h>

#include "segment.h"
#include "alloc.h"

int		read_segment(Datas	*DataExec, int id)
{
	int i;

	i = 0;
	while (DataExec->memory[i].id != -1)
		{
			if (DataExec->memory[i].id == id)
				return DataExec->memory[i].value;
			++i;
		}
	return (0);
}

void	write_new_segment(Datas	*DataExec, int id, int value)
{
	int i;

	i = 0;
	while (DataExec->memory[i].id != -1)
			++i;
	DataExec->memory = xrealloc(DataExec->memory, (i + 2) * sizeof(Segment));
	DataExec->memory[i].id = id;
	DataExec->memory[i].value = value;
	DataExec->memory[i + 1].id = -1;
	DataExec->memory[i + 1].value = 0;
}

void	write_segment(Datas	*DataExec, int id, int value)
{
	int i;
	int exist;

	i = exist = 0;
	while (DataExec->memory[i].id != -1)
		{
			if (DataExec->memory[i].id == id)
				{
					exist = 1;
					DataExec->memory[i].value = value;
					break;
				}
			++i;
		}
	if (!exist)
		write_new_segment(DataExec, id, value);
}

void	create_segment(Datas	*DataExec)
{
	DataExec->memory = xmalloc(sizeof(Segment), "Cannot allocate segment\n");
	DataExec->memory[0].id = -1;
	DataExec->memory[0].value = 0;
}

#ifdef DEBUG
void		printf_debug_segment(Datas	*DataExec)
{
	int i;

	i = 0;
	while (DataExec->memory[i].id != -1)
		{
			printf("Segment[%d] = %d\n", DataExec->memory[i].id, DataExec->memory[i].value);
			++i;
		}
}
#endif
