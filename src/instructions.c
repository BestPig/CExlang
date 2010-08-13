/*
** instructions.c
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/
#include <stdio.h>
#include <stdlib.h>

#include "instructions.h"
#include "alloc.h"
#include "lib.h"

void	instruction_0(Datas	*DataExec, int arg1, int arg2)
{
	(void) arg1;
	(void) arg2;
	DataExec->stop = 0;
}

void	instruction_1(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment, (read_segment(DataExec, DataExec->currentSegment) + arg1));
	DataExec->currentInstruction += arg2;
}

void	instruction_2(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment, (read_segment(DataExec, DataExec->currentSegment) - arg1));
	DataExec->currentInstruction += arg2;
}

void	instruction_3(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment, arg1);
	DataExec->currentInstruction += arg2;
}

void	instruction_4(Datas	*DataExec, int arg1, int arg2)
{
	DataExec->currentSegment += arg1;
	DataExec->currentInstruction += arg2;
}

void	instruction_5(Datas	*DataExec, int arg1, int arg2)
{
	DataExec->currentSegment -= arg1;
	DataExec->currentInstruction += arg2;
}

void	instruction_6(Datas	*DataExec, int arg1, int arg2)
{
	DataExec->currentSegment = arg1;
	DataExec->currentInstruction += arg2;
}

void	instruction_7(Datas	*DataExec, int arg1, int arg2)
{
	if (read_segment(DataExec, DataExec->currentSegment) == arg1)
		DataExec->currentInstruction += 1;
	else
		DataExec->currentInstruction += arg2;
}

void	instruction_8(Datas	*DataExec, int arg1, int arg2)
{
	if (read_segment(DataExec, DataExec->currentSegment) == arg1)
		DataExec->currentInstruction += arg2;
	else
		DataExec->currentInstruction += 1;
}

void	instruction_9(Datas	*DataExec, int arg1, int arg2)
{
	if (read_segment(DataExec, DataExec->currentSegment) < arg1)
		DataExec->currentInstruction += 1;
	else
		DataExec->currentInstruction += arg2;
}

void	instruction_10(Datas	*DataExec, int arg1, int arg2)
{
	if (read_segment(DataExec, DataExec->currentSegment) < arg1)
		DataExec->currentInstruction += arg2;
	else
		DataExec->currentInstruction += 1;
}

void	instruction_11(Datas	*DataExec, int arg1, int arg2)
{
	if (read_segment(DataExec, DataExec->currentSegment) <= arg1)
		DataExec->currentInstruction += 1;
	else
		DataExec->currentInstruction += arg2;
}

void	instruction_12(Datas	*DataExec, int arg1, int arg2)
{
	if (read_segment(DataExec, DataExec->currentSegment) <= arg1)
		DataExec->currentInstruction += arg2;
	else
		DataExec->currentInstruction += 1;
}

void	instruction_13(Datas	*DataExec, int arg1, int arg2)
{
	if (read_segment(DataExec, arg1) == read_segment(DataExec, arg2))
		DataExec->currentInstruction += 1;
	else
		DataExec->currentInstruction += 2;
}

void	instruction_14(Datas	*DataExec, int arg1, int arg2)
{
	if (read_segment(DataExec, arg1) < read_segment(DataExec, arg2))
		DataExec->currentInstruction += 1;
	else
		DataExec->currentInstruction += 2;
}

void	instruction_15(Datas	*DataExec, int arg1, int arg2)
{
	if (read_segment(DataExec, arg1) <= read_segment(DataExec, arg2))
		DataExec->currentInstruction += 1;
	else
		DataExec->currentInstruction += 2;
}

void	instruction_16(Datas	*DataExec, int arg1, int arg2)
{
	DataExec->currentInstruction += (arg1 - arg2);
}

void	instruction_17(Datas	*DataExec, int arg1, int arg2)
{
	DataExec->currentInstruction = (arg1 - arg2);
}

void	instruction_18(Datas	*DataExec, int arg1, int arg2)
{
	(void) arg2;
	DataExec->currentInstruction += arg1;
}

void	instruction_19(Datas	*DataExec, int arg1, int arg2)
{
	(void) arg2;
	DataExec->currentInstruction = read_segment(DataExec, arg1);
}

void	instruction_20(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, arg1, DataExec->currentInstruction);
	DataExec->currentInstruction += arg2;
}

void	instruction_21(Datas	*DataExec, int arg1, int arg2)
{
	my_write(arg1);
	DataExec->currentInstruction += arg2;
}

void	instruction_22(Datas	*DataExec, int arg1, int arg2)
{
	my_write(read_segment(DataExec, arg1));
	DataExec->currentInstruction += arg2;
}

void	instruction_23(Datas	*DataExec, int arg1, int arg2)
{
	(void) arg2;
	my_write(read_segment(DataExec, DataExec->currentSegment));
	DataExec->currentInstruction += arg1;
}

void	instruction_24(Datas	*DataExec, int arg1, int arg2)
{
	if (DataExec->argc > (arg1 + 2))
	{
		if (is_numeric(DataExec->argv[arg1 + 2]))
			write_segment(DataExec, DataExec->currentSegment, my_getnbr(DataExec->argv[arg1 + 2]));
		else
			write_segment(DataExec, DataExec->currentSegment, 0);
	}
	DataExec->currentInstruction += arg2;
}

void	instruction_25(Datas	*DataExec, int arg1, int arg2)
{
	if (DataExec->argc > (arg1 + 2))
	{
		if (is_numeric(DataExec->argv[arg1 + 2]))
			write_segment(DataExec, arg2, my_getnbr(DataExec->argv[arg1 + 2]));
		else
			write_segment(DataExec, arg2, 0);
	}
	DataExec->currentInstruction += 1;
}

void	instruction_26(Datas	*DataExec, int arg1, int arg2)
{
	my_putstr("J'aime les bonbons tralalilala !");
	(void )DataExec;
	(void) arg1;
	(void) arg2;
	DataExec->currentInstruction += 1;
}

void	instruction_27(Datas	*DataExec, int arg1, int arg2)
{
	my_putnbr(arg1);
	DataExec->currentInstruction += arg2;
}

void	instruction_28(Datas	*DataExec, int arg1, int arg2)
{
	my_putnbr(read_segment(DataExec, arg1));
	DataExec->currentInstruction += arg2;
}

void	instruction_29(Datas	*DataExec, int arg1, int arg2)
{
	(void) arg2;
	my_putnbr(read_segment(DataExec, DataExec->currentSegment));
	DataExec->currentInstruction += arg1;
}

void	instruction_30(Datas	*DataExec, int arg1, int arg2)
{
	(void) arg1;
	(void) arg2;
	DataExec->currentInstruction += 1;
}

void	instruction_31(Datas	*DataExec, int arg1, int arg2)
{
	char prompt;
	
	prompt = my_read();
	clear_stdin();
	if (prompt == '\n')
		write_segment(DataExec, DataExec->currentSegment, 0);
	else
		write_segment(DataExec, DataExec->currentSegment, prompt);
	(void) arg2;
	DataExec->currentInstruction += arg1;
}

void	instruction_32(Datas	*DataExec, int arg1, int arg2)
{
	char prompt;
	
	prompt = my_read();
	if (prompt == '\n')
		write_segment(DataExec, arg1, 0);
	else
		write_segment(DataExec, arg1, prompt);
	(void) arg2;
	DataExec->currentInstruction += arg2;
}

void	instruction_33(Datas	*DataExec, int arg1, int arg2)
{
	char	*prompt;

	prompt = xmalloc(BUFSIZ + 1, "Cannot allocate for reading string\n");
	prompt = my_readstr();
	if (my_strlen(prompt) == 0 || !is_numeric(prompt))
		{
		write_segment(DataExec, DataExec->currentSegment, 0);
		}
	else
		{
		write_segment(DataExec, DataExec->currentSegment, my_getnbr(prompt));
		}
	(void) arg2;
	DataExec->currentInstruction += arg1;
	free(prompt);
}

void	instruction_34(Datas	*DataExec, int arg1, int arg2)
{
	char	*prompt;

	prompt = xmalloc(BUFSIZ + 1, "Cannot allocate for reading string\n");
	prompt = my_readstr();
	if (my_strlen(prompt) == 0 || !is_numeric(prompt))
		write_segment(DataExec, arg1, 0);
	else
		write_segment(DataExec, arg1, my_getnbr(prompt));
	(void) arg2;
	DataExec->currentInstruction += arg2;
	free(prompt);
}

void	instruction_35(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment, (read_segment(DataExec, DataExec->currentSegment) * arg1));
	DataExec->currentInstruction += arg2;
}

void	instruction_36(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment, (read_segment(DataExec, DataExec->currentSegment) / arg1));
	DataExec->currentInstruction += arg2;
}

void	instruction_37(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment, (read_segment(DataExec, DataExec->currentSegment) % arg1));
	DataExec->currentInstruction += arg2;
}

void	instruction_38(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment, 
		(read_segment(DataExec, DataExec->currentSegment) + read_segment(DataExec, arg1)));
	DataExec->currentInstruction += arg2;
}

void	instruction_39(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment, 
		(read_segment(DataExec, DataExec->currentSegment) - read_segment(DataExec, arg1)));
	DataExec->currentInstruction += arg2;
}

void	instruction_40(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment, 
		(read_segment(DataExec, DataExec->currentSegment) * read_segment(DataExec, arg1)));
	DataExec->currentInstruction += arg2;
}

void	instruction_41(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment, 
		(read_segment(DataExec, DataExec->currentSegment) / read_segment(DataExec, arg1)));
	DataExec->currentInstruction += arg2;
}

void	instruction_42(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment,
		read_segment(DataExec, DataExec->currentSegment) % read_segment(DataExec, arg1));
	DataExec->currentInstruction += arg2;
}

void	instruction_43(Datas	*DataExec, int arg1, int arg2)
{
	write_segment(DataExec, DataExec->currentSegment,
		read_segment(DataExec, arg1));
	DataExec->currentInstruction += arg2;
}
