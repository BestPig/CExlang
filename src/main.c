/*
** main.c
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#ifdef OPENCV
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include "img.h"
#else
#include "read_bmp.h"
#endif
#include "types.h"
#include "alloc.h"
#include "segment.h"
#include "instructions.h"
#include "lib.h"

#define NBINSTRUCTION 44

void	(*exec[])() = { instruction_0, instruction_1, instruction_2,
		instruction_3, instruction_4, instruction_5, instruction_6,
		instruction_7, instruction_8, instruction_9, instruction_10, 
		instruction_11, instruction_12, instruction_13, instruction_14, 
		instruction_15, instruction_16, instruction_17, instruction_18,
		instruction_19, instruction_20, instruction_21, instruction_22,
		instruction_23, instruction_24, instruction_25, instruction_26, 
		instruction_27, instruction_28, instruction_29, instruction_30,
		instruction_31, instruction_32, instruction_33, instruction_34,
		instruction_35, instruction_36, instruction_37, instruction_38, 
		instruction_39, instruction_40, instruction_41, instruction_42,
		instruction_43 
};

void	exec_instructions(Pixel	*Instructions, int nb, Datas	*DataExec)
{
	int i;

	i = 0;
	while (((i = DataExec->currentInstruction) < nb) && DataExec->stop)
		{
			if (Instructions[i].red <= (NBINSTRUCTION - 1))
				{
					exec[Instructions[i].red](DataExec, Instructions[i].green, Instructions[i].blue);
					#ifdef DEBUG
					my_putstr("--Instruction : %d-- (Appuyer sur entrée pour continuer)\n", Instructions[i].red);
					printf_debug_segment(DataExec);
					clear_stdin();
					#endif
				}
			else
				{
					fprintf(stderr, "Instruction %d dont't exist.", Instructions[i].red);
					break;
				}
		}
}

int main(int argc, char** argv)
{
	#ifdef OPENCV
	IplImage *img;
	#else
	bmp_dib_v3_header_t		dib_header;
	#endif
	Datas	DataExec;
	const char *imagename = argc > 1 ? argv[1] : "";
	Pixel	*Instructions;
	
	Instructions = NULL;
	create_segment(&DataExec);
	DataExec.stop = 1;
	DataExec.currentInstruction = DataExec.currentSegment = 0;
	DataExec.argc = argc;
	DataExec.argv = argv;

	if (argc > 1)
		{
			#ifdef OPENCV
			img = cvLoadImage(imagename, CV_LOAD_IMAGE_COLOR);
			if(img)
				Instructions = read_img(img);
			#else
			Instructions = read_img(imagename, &dib_header, Instructions);
			#endif
			
			if (Instructions != NULL)
			#ifdef OPENCV
				exec_instructions(Instructions, img->height * img->width, &DataExec);
			#else
				exec_instructions(Instructions, dib_header.height * dib_header.width, &DataExec);
			#endif
			else
				{
					fprintf(stderr, "L'image n'est pas un bmp correct : %s\n", imagename);
					exit(1);
				}

			free(Instructions);
		}
	else
		{
			my_putstr("CExlang Interpreteur version 1.0 by BestPig.\n"
			"Cette version est compatible avec L'exlang 0.8.\n");
			my_putstr("   Utilisation : ");
			my_putstr(argv[0]);
			my_putstr(" image.bmp [arg0] [arg1] ...\n");
			#ifdef OPENCV
			my_putstr("Cette interpreteur gère la plupart des formats png, bmp etc...");
			#else
			my_putstr("Cette interpreteur gère uniquement les bmp 24-bit non compressé.");
			#endif
		}
	my_putstr("\n");
	return 0;
}
