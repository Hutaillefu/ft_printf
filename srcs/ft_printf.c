/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <htaillef@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 15:58:09 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 15:45:34 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	end(char *buf)
{
	ft_putstr(buf);
	ft_memdel((void **)&buf);
}

void	nln(char **buf, char **format, int *chars)
{
	*buf = ft_strnjoin(*buf, (*format)++, 1);
	(*chars)++;
}

int		nln1(char **buf, char **format, t_format **infos, va_list *args)
{
	ft_putstr(*buf);
	ft_memdel((void **)buf);
	*buf = ft_strdup("");
	(*format)++;
	*infos = extract(format);
	return (display_format(*infos, args));
}

int		process(char **format, va_list *args)
{
	int			i;
	int			chars;
	t_format	*infos;
	char		*buf;
	int			res;

	buf = ft_strdup("");
	chars = 0;
	i = 0;
	while (**format)
	{
		if ((**format) == '%')
		{
			res = nln1(&buf, format, &infos, args);
			if (res == -1)
				return (res);
			chars += res;
			free_format(&infos);
		}
		else
			nln(&buf, format, &chars);
	}
	end(buf);
	return (chars);
}

int		ft_printf(const char *restrict format, ...)
{
	int		chars;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	chars = process((char **)&format, &args);
	va_end(args);
	return (chars);
}
