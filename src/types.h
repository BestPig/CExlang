/*
** types.h
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/
#ifndef TYPES_H_
# define TYPES_H_

typedef struct _pixels {
	int		red;
	int		green;
	int		blue;
} Pixel;

typedef struct {
	unsigned char	magic[2];
	unsigned int	filesz;
	unsigned short	creator1;
	unsigned short	creator2;
	unsigned int	bmp_offset;
	unsigned int	header_sz;
	unsigned int	width;
	unsigned int	height;
	unsigned short	nplanes;
	unsigned short	bitspp;
	unsigned int	compress_type;
	unsigned int	bmp_bytesz;
	unsigned int	hres;
	unsigned int	vres;
	unsigned int	ncolors;
	unsigned int	nimpcolors;
	short			align;
} bmp_dib_v3_header_t;
#endif /* !TYPES_H_ */
