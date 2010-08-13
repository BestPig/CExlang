/*
** img.h
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/
#ifndef IMG_H_
# define IMG_H_

#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

#include "types.h"

Pixel	*read_img(IplImage *img);
#endif /* !IMG_H_ */
