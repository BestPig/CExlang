/*
** read_bmp.c
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alloc.h"
#include "lib.h"
#include "types.h"
#include "read_bmp.h"

Pixel		*reverse_bmp(bmp_dib_v3_header_t	*dib_header,Pixel	*img)
{
	unsigned int pos;
	unsigned int i      = 0;
	Pixel	*new_img;

	pos = 0;
	new_img = xmalloc(dib_header->height * dib_header->width * sizeof(Pixel), "Cannot allocate new_img.");
	init_pixel(new_img, dib_header->width * dib_header->height);
	i = dib_header->width * dib_header->height - dib_header->width;
	while (pos < (dib_header->width * dib_header->height) && img[i].red != -1)
		{
			new_img[pos].blue = img[i].blue;
			new_img[pos].green = img[i].green;
			new_img[pos].red = img[i].red;
			++i;
			if ((i % dib_header->width) == 0)
				i -= dib_header->width * 2;
			++pos;
		}
	free(img);
	return (new_img);
}

void		init_pixel(Pixel	*img, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
		{
			img[i].red = img[i].green = img[i].blue = -1;
			++i;
		}
}

unsigned int	alignement(bmp_dib_v3_header_t	*dib_header)
{
	return ((dib_header->bmp_bytesz - (3 * dib_header->width * dib_header->height)) / dib_header->height);
}


Pixel		*read_bmp(FILE *pFile,
					bmp_dib_v3_header_t		*dib_header)
{
	unsigned char	tmp_str[1];
	unsigned int	i;
	Pixel			*img;
	unsigned char	retour;

	img = xmalloc(dib_header->height * dib_header->width * sizeof(Pixel), "Cannot allocate img.");
	init_pixel(img, dib_header->width * dib_header->height);
	i = 0;
	while (i < (dib_header->width * dib_header->height))
		{
			if (dib_header->align && i % (dib_header->width) == 0 && i > 0)
				fseek(pFile, dib_header->align, SEEK_CUR);
			retour = xfread(tmp_str, 1, 1, pFile);
			img[i].blue = (!retour) ? -1 : str_to_dec(tmp_str, 1);
			retour = xfread(tmp_str, 1, 1, pFile);
			img[i].green = (!retour) ? -1 : str_to_dec(tmp_str, 1);
			retour = xfread(tmp_str, 1, 1, pFile);
			img[i].red = (!retour) ? -1 : str_to_dec(tmp_str, 1);
			++i;
		}
	return (reverse_bmp(dib_header, img));
}

long unsigned int	read_dib_header(FILE *pFile,
						bmp_dib_v3_header_t		*dib_header,
						long unsigned int cur)
{
	unsigned char tmp_str[10];

	cur += fread (tmp_str, 1, 4, pFile);
	dib_header->header_sz = str_to_dec(tmp_str, 4);
	cur += fread (tmp_str, 1, 4, pFile);
	dib_header->width = str_to_dec(tmp_str, 4);
	cur += fread (tmp_str, 1, 4, pFile);
	dib_header->height = str_to_dec(tmp_str, 4);
	cur += fread (tmp_str, 1, 2, pFile);
	dib_header->nplanes = str_to_dec(tmp_str, 2);
	cur += fread (tmp_str, 1, 2, pFile);
	dib_header->bitspp = str_to_dec(tmp_str, 2);
	cur += fread (tmp_str, 1, 4, pFile);
	dib_header->compress_type = str_to_dec(tmp_str, 4);
	cur += fread (tmp_str, 1, 4, pFile);
	dib_header->bmp_bytesz = str_to_dec(tmp_str, 4);
	cur += fread (tmp_str, 1, 4, pFile);
	dib_header->hres = str_to_dec(tmp_str, 4);
	cur += fread (tmp_str, 1, 4, pFile);
	dib_header->vres = str_to_dec(tmp_str, 4);
	cur += fread (tmp_str, 1, 4, pFile);
	dib_header->ncolors = str_to_dec(tmp_str, 4);
	cur += fread (tmp_str, 1, 4, pFile);
	dib_header->nimpcolors = str_to_dec(tmp_str, 4);
	dib_header->align = alignement(dib_header);
	return (cur);
}

int			is_correct_img(Pixel	*Instructions, bmp_dib_v3_header_t	*dib_header)
{
	unsigned int i;

	i = 0;
	if (dib_header->compress_type != 0 || dib_header->bitspp != 24)
		return (0);
	while (i < (dib_header->height * dib_header->width) && Instructions[i].red != -1)
		++i;
	if (i != (dib_header->height * dib_header->width))
		return (0);

	return (1);
}

Pixel		*read_img(const char *filename,
					bmp_dib_v3_header_t		*dib_header,
					Pixel	*Instructions)
{
	FILE * pFile;
	unsigned char tmp_str[10];
	long unsigned int cur;

	cur = 0;
	pFile = fopen(filename, "rb");
	if (pFile != NULL)
	{
		cur += fread (dib_header->magic, 1, 2, pFile);
		if (dib_header->magic[0] != 'B' || dib_header->magic[1] != 'M')
			return (NULL);
		cur += fread (tmp_str, 1, 4, pFile);
		dib_header->filesz = str_to_dec(tmp_str, 4);
		fseek(pFile, 4, SEEK_CUR);
		cur += 4;
		cur += fread (tmp_str, 1, 4, pFile);
		dib_header->bmp_offset = str_to_dec(tmp_str, 4);
		cur = read_dib_header(pFile, dib_header, cur);
		Instructions = read_bmp(pFile, dib_header);
		fclose (pFile);
		if (is_correct_img(Instructions, dib_header))
			return (Instructions);
	}
	return (NULL);	
}
