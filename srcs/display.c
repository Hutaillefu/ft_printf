/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 19:35:21 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 19:35:23 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
 ** Puts on stdout n char from str.
*/
void display(const char *str, int n)
{
	int i;
	if (!str || n <= 0)
		return;
	i = 0;
	while (str[i] && i < n)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int display_short_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;

	res = ft_itoa(va_arg(*args, int));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_int_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;
	res = ft_itoa(va_arg(*args, int));
	ft_putstr(res);
	return (ft_strlen(res));
	return (0);
}

int display_string_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;

	res = va_arg(*args, char *);
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_base_type(t_format *infos, va_list *args, int base, t_bool capital)
{
	char *res;
	(void)infos;

	res = ft_itoa_base(va_arg(*args, unsigned int), base, capital);
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_char_type(t_format *infos, va_list *args)
{
	char res;

	(void)infos;
	res = va_arg(*args, int);
	ft_putchar(res);
	return (1);
}

int display_long_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;

	res = ft_itoa(va_arg(*args, long));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_longlong_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;

	res = ft_itoa(va_arg(*args, long long));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_sizet_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;

	res = ft_itoa(va_arg(*args, size_t));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_intmaxt_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;

	res = ft_itoa(va_arg(*args, intmax_t));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_format(t_format *infos, va_list *args)
{
	if (!(infos->type))
		return 0;
	if (infos->type == 'i' || infos->type == 'd')
	{
		if (infos->modifier)
		{
			if (ft_strcmp(infos->modifier, "l") == 0)
				return display_long_type(infos, args);
			if (ft_strcmp(infos->modifier, "ll") == 0)
				return display_longlong_type(infos, args);
			if (ft_strcmp(infos->modifier, "z") == 0)
				return display_sizet_type(infos, args);
			if (ft_strcmp(infos->modifier, "j") == 0)
				return display_intmaxt_type(infos, args);
		}
		return display_int_type(infos, args); // modifier h or hh call int
	}
	else if (infos->type == 's')
		return display_string_type(infos, args);
	else if (infos->type == 'X' || infos->type == 'x')
		return display_base_type(infos, args, 16, infos->type == 'X');
	else if (infos->type == 'o')
		return display_base_type(infos, args, 8, FALSE);
	return (0);
}
