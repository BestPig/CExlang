/*
** segment.c
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/
#ifndef SEGMENT_H_
# define SEGMENT_H_

typedef struct _segment {
	int		id;
	int		value;
} Segment;

typedef struct _datas {
	int		currentSegment;
	int		currentInstruction;
	int		value;
	int		stop;
	int		argc;
	char	**argv;
	Segment *memory;
} Datas;

int		read_segment(Datas	*DataExec, int id);
void	write_new_segment(Datas	*DataExec, int id, int value);
void	write_segment(Datas	*DataExec, int id, int value);
void	create_segment(Datas	*DataExec);
#ifdef DEBUG
void	printf_debug_segment(Datas	*DataExec);
#endif
#endif /* !SEGMENT_H_ */
