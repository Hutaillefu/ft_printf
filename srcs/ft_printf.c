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

char *process(char **format, va_list *args)
{
	int 		i;
	char		*buffer;
	t_format 	*infos;

	buffer = ft_strdup("");
	if (!buffer)
		return (NULL);

	i = 0;
	while ((*format)[i])
	{
		if ((*format)[i] == '%')
		{
			buffer = ft_strnjoin(buffer, *format, i); // affiche le text avant le %
			if ((*format)[i + 1] && (*format)[i + 1] == '%')
			{
				*format = resize(*format, i);
				buffer = ft_strjoin(buffer, "%");
				*format = resize(*format, 2);
				i = 0;
			}
			else
			{
				*format = resize(*format, i + 1); // supprime le text et le %
				infos = extract(format);		  // extrait les infos du %
				i = 0;
				display_format(infos, args, &buffer); // affiche le format
				// clear_infos(&infos);            // supprime la structure
			}
			continue;
		}
		i++;
	}
	buffer = ft_strjoin(buffer, *format);
	return (buffer);
}

int ft_printf(const char *restrict format, ...)
{
	char *buffer;
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);
	buffer = process((char **)&format, &args);
	if (!buffer)
		return (-1);
	va_end(args);
	ft_putstr(buffer);
	return (ft_strlen(buffer));
}
