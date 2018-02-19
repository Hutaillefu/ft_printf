/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <htaillef@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 15:58:09 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 18:54:44 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		process(char **format, va_list *args)
{
	int			i;
	int			chars;
	t_format	*infos;
	char		*buf;
	int res;

	buf = ft_strdup("");
	chars = 0;
	i = 0;
	while (**format)
	{
		if ((**format) == '%')
		{
			ft_putstr(buf);
			ft_memdel((void **)&buf);
			buf = ft_strdup("");
			(*format)++;
			infos = extract(format);
			res = display_format(infos, args);
			if (res == -1)
				return (res);
			chars += res;
			free_format(&infos);
		}
		else
		{
			buf = ft_strnjoin(buf, (*format)++, 1);
			chars++;
		}
	}
	ft_putstr(buf);
	ft_memdel((void **)&buf);
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
