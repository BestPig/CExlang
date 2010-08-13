/*
** read_bmp.h
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/
#ifndef READ_HEADER_H_
# define READ_HEADER_H_

#include "types.h"

void				init_pixel(Pixel	*img, unsigned int size);

unsigned int		alignement(bmp_dib_v3_header_t	*dib_header);

long unsigned int	read_dib_header(FILE *pFile,
						bmp_dib_v3_header_t		*dib_header,
						long unsigned int cur);

Pixel	*read_bmp(FILE *pFile,
					bmp_dib_v3_header_t		*dib_header);

Pixel	*read_img(const char *filename,
					bmp_dib_v3_header_t		*dib_header,
					Pixel	*Instructions);
#endif /* !READ_HEADER_H_ */
