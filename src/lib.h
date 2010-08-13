/*
** lib.h
**
** Made by BestPig
** Email   <bestpig82@gmail.com>
** Website http://www.bestpig.fr
**
*/
#ifndef LIB_H_
# define LIB_H_

void	my_write(char c);
char	my_read(void);
void	my_putstr(char *str);
void	my_putnbr(int nb);
void	clear_stdin(void);
size_t	my_strlen(char const * const str);
int		my_getnbr(char *str);
int		is_numeric(char	*str);
char	*my_readstr(void);
size_t	xfread(void *ptr, size_t size, size_t nmemb, FILE *stream);
int		str_to_dec(unsigned char *str, int nb);

#endif /* !lib_H_ */
