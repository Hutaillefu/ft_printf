/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 16:01:43 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 16:01:45 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int     ft_printf(const char * restrict format, ...);

typedef enum
{
    FALSE = 0,
    TRUE = 1
}               t_bool;

typedef struct  s_flags
{
    t_bool  left_justify;   // Left justify.
    t_bool  padding;        // Field is padded with 0's instead of blanks.
    t_bool  positive;       // Sign of number always O/P.
    t_bool  blank;          // Positive values begin with a blank.
    t_bool  diese;          // Various uses.
}               t_flags;

typedef struct  s_format
{
    t_flags *flags;
    int     min_width;
    t_bool  period;
    int     precision;
    char    *modifier;
    char    type;
}               t_format;

/* LIBFT  */
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strncat(char *dst, const char *src, size_t n);
char	*ft_itoall(long long n);
char	*ft_itoaull(unsigned long long n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void    display(const char *str, int n);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
char	*ft_itoall_base(long long n, int base, t_bool capital);
char 	*ft_itoaull_base(unsigned long long n, unsigned long long base, t_bool capital);

char    *resize(char *str, int n);

/* Struct */
t_format            *new_format(void);
t_format *extract(char **str);

int    display_format(t_format *infos, va_list *args);
#endif
