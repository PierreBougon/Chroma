/*
** my.h for my in /home/theis_p/my_printf
**
** Made by theis_p
** Login   <theis_p@epitech.net>
**
** Started on  Sat Nov  7 17:05:42 2015 theis_p
** Last update Fri Jan  8 13:50:39 2016 Paul THEIS
*/

#ifndef MY_H_
# define MY_H_

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define	READ_SIZE	4096

int	my_putchar(char c);
int	my_isneg(int nb);
int	my_putnbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_putstr_err(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb,int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char*src,int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1,char *s2);
int	my_strncmp(char *s1,char *s2,int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_char_isprintable(char c);
int	my_char_isalpha(char c);
int	my_char_isnum(char c);
int	my_putnbr_base(int n, char *base);
int	my_putnbr_base_addr(unsigned long n, char *base);
int	my_putnbr_base_unsigned(unsigned int n, char *base);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_putstr_err(char *str);
int	my_atoi(const char *str);
int	my_printf(const char *format, ...);
char	**my_str_to_word_tab(char *str);
char	*my_strdup(char *str);
char	*get_next_line(const int fd);
void	*my_memset(void *b, int c, size_t len);
void	my_bzero(void *s, size_t n);

#endif /* !MY_H_ */
