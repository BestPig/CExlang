/*
** lib.c
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/

#include <stdio.h>
#include <stdlib.h>

#include "alloc.h"

void	my_write(char c)
{
	fwrite(&c, 1, 1, stdout);
}

char	my_read(void)
{
	char	c;

	return ((fread(&c, 1, 1, stdin)) ? c : 0);
}

void	my_putstr(char *str)
{
	while(*str)
		my_write(*str++);
}

void my_putnbr(int nb)
{
	int i;
	
	i = 1;
	if (nb < 0)
    	{
			nb *= -1;
			my_write('-');
		}
	if (nb == 0)
		my_write('0');
	while (nb / i)
		i *= 10;
	i /= 10;
	while (i)
		{
			my_write('0' + nb / i);
			nb -=(nb / i) * i;
			i /= 10;
		}
} 

void	clear_stdin(void)
{
	char c;

	c = 0;
	while ((c = getchar()) != '\n');
}

size_t		my_strlen(char const * const str)
{
	size_t i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		my_getnbr(char *str)
{
	int i;
	int len;
	int nb;

	i = 1;
	len = my_strlen(str) - 1;
	nb = 0;
	while (len >= 0)
		{
			nb += (str[len] - '0') * i;
			i *= 10;
			--len;
		}
	return (nb);
}

int		is_numeric(char	*str)
{
	size_t i;
	int    numeric;

	i = 0;
	numeric = 1;
	while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				numeric = 0;
			++i;
		}
	return (numeric);
}

char	*my_readstr(void)
{
	size_t	i;
	char	*buff;

	buff = xmalloc(BUFSIZ + 1, "Cannot allocate for reading string\n");
	i = 0;
	while(((buff[i] = my_read()) != '\n') && i <= BUFSIZ)
		++i;
	buff[i] = '\0';
	return (buff);
}

size_t	xfread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
	size_t len;

	len = fread (ptr, size, nmemb, stream);
	/*ptr[len] = '\0';*/
	if (len != nmemb)
	{
		fprintf(stderr, "Read file error\n");
		fclose(stream);
		exit(EXIT_FAILURE);
	}
	return (len);
}

int	str_to_dec(unsigned char *str, int nb)
{
	int res;
	int i;

	res = 0;
	i = nb - 1;
	while (i >= 0)
		{
			res = res * 256 + str[i];
			--i;
		}
	return (res);
}

