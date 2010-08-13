/*
** img.c
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/
#include <stdio.h>

#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

#include "alloc.h"
#include "types.h"

Pixel	*read_img(IplImage *img)
{
	int i;
	int j;
	int k;
	int l;
	uchar *data;
	Pixel	*Instructions;

	i = l = 0;
	data      = (uchar *)img->imageData;
	Instructions = xmalloc(img->height * img->width * sizeof(Pixel), "Cannot allocate instruction");
	while (i < img->height)
		{
			j = 0;
			while (j < img->width)
				{
					k = 0;
					while (k < img->nChannels)
						{
							if (k == 0)
								Instructions[l].blue = data[i * img->widthStep + j * img->nChannels+k];
							else if (k == 1)
								Instructions[l].green = data[i * img->widthStep + j * img->nChannels+k];
							else
								Instructions[l].red = data[i * img->widthStep + j * img->nChannels+k];
							++k;
						}
					++l;
					++j;
				}
			++i;
		}
	return Instructions;
}
