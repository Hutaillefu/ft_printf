/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 15:58:09 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 15:58:14 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int process(char **format, va_list *args)
{
	int i;
	int chars;
	t_format *infos;
	chars = 0;
	i = 0;
	while (**format)
	{
		if ((**format) == '%')
		{
			(*format)++;
			if (**format && **format == '%')
			{
				(*format)++;
				ft_putchar('%');
				chars++;
			}
			else
			{
				infos = extract(format);			  // extrait les infos du %
				chars += display_format(infos, args); // affiche le format
			}
		}
		else
		{
			ft_putchar(**format);
			(*format)++;
			chars++;
		}
	}
	return (chars);
}

int ft_printf(const char *restrict format, ...)
{
	int chars;
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);
	chars = process((char **)&format, &args);
	if (chars == -1)
		return (-1);
	va_end(args);
	return (chars);
}
