/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <htaillef@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 16:01:43 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 18:14:15 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

int				ft_printf(const char * restrict format, ...);

typedef enum
{
                FALSE = 0,
                TRUE = 1
}               t_bool;

typedef struct  s_flags
{
    t_bool      left_justify;
    t_bool      padding;
    t_bool      positive;
    t_bool      blank;
    t_bool      diese;
}               t_flags;

typedef	union	u_type
{
	int			t_int;
	long		t_long;
	long long	t_long_long;
	size_t		t_size_t;
	intmax_t	t_intmax_t;
	char		t_char;
	short		t_short;
}				t_type;

typedef struct  s_format
{
    t_flags		*flags;
    size_t		min_width;
    t_bool		period;
    size_t		precision;
    char		*modifier;
	char		type;
	t_bool		is_numeric;
	t_bool		is_negative;
}               t_format;

void            ft_putchar_fd(char c, int fd);
void            ft_putchar(char c);
void            ft_putnbr_fd(int n, int fd);
void        	ft_putnbr(int n);
void	    	ft_putstr_fd(char const *s, int fd);
void	        ft_putstr(char const *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strncat(char *dst, const char *src, size_t n);
char			*ft_itoall(long long n);
char			*ft_itoaull(unsigned long long n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			ft_memdel(void **ap);

void    		display(const char *str, int n);
char			*ft_strnjoin(char *s1, char const *s2, size_t n);
char			*ft_itoall_base(long long n, int base, t_bool capital);
char 			*ft_itoaull_base(unsigned long long n, unsigned long long base, t_bool capital);

t_format		*new_format(void);
t_format		*extract(char **str);
void			free_format(t_format **format);

int				display_format(t_format *infos, va_list *args);

int				wcharlen(wchar_t wchar);
char            *wchartostr(wchar_t wchar);
#endif
