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
#include <stdio.h>

int process(char **format, va_list *args)
{
	int i;
	int chars;
	t_format *infos;

	chars = 0;
	i = 0;
	while ((*format)[i])
	{
		if ((*format)[i] == '%')
		{
			display(*format, i); // affiche le text avant le %
			chars += i;
			if ((*format)[i + 1] && (*format)[i + 1] == '%')
			{
				*format = resize(*format, i);
				ft_putchar('%');
				chars++;
				*format = resize(*format, 2);
				i = 0;
			}
			else
			{
				*format = resize(*format, i + 1); // supprime le text et le %
				infos = extract(format);		  // extrait les infos du %
				i = 0;
				chars += display_format(infos, args); // affiche le format
															   // clear_infos(&infos);            // supprime la structure
			}
			continue;
		}
		i++;
	}
	ft_putstr(*format);
	chars += ft_strlen(*format);
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
