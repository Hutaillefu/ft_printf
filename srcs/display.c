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

int display_int_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;
	res = ft_itoall(va_arg(*args, int));
	ft_putstr(res);
	return (ft_strlen(res));
	return (0);
}

int display_string_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;

	res = va_arg(*args, char *);
	if (!res)
	{
		ft_putstr("null");
		return (4);
	}
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_base_type(t_format *infos, va_list *args, int base, t_bool capital)
{
	char *res;
	(void)infos;

	res = ft_itoall_base(va_arg(*args, unsigned int), base, capital);
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_base_type_val(t_format *infos, long long val, int base, t_bool capital)
{
	char *res;
	(void)infos;

	res = ft_itoall_base(val, base, capital);
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_uint_type(t_format *infos, va_list *args)
{
	char *res;

	(void)infos;
	res = ft_itoall(va_arg(*args, unsigned int));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_ushort_type(t_format *infos, va_list *args)
{
	char *res;

	(void)infos;
	res = ft_itoall((unsigned short)va_arg(*args, unsigned int));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_ulong_type(t_format *infos, va_list *args)
{
	char *res;

	(void)infos;
	res = ft_itoall(va_arg(*args, unsigned long));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_ulonglong_type(t_format *infos, va_list *args)
{
	char *res;

	(void)infos;
	res = ft_itoaull(va_arg(*args, unsigned long long));
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

int display_uchar_type(t_format *infos, va_list *args)
{
	unsigned char res;

	(void)infos;
	res = va_arg(*args, int);
	ft_putchar(res);
	return (1);
}

int display_long_type(t_format *infos, va_list *args)
{
	char *res;
	int len;
	(void)infos;

	res = ft_itoall(va_arg(*args, long));
	ft_putstr(res);
	len = ft_strlen(res);
	free(res);
	res = NULL;
	return (len);
}

int display_longlong_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;

	res = ft_itoall(va_arg(*args, long long));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_sizet_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;

	res = ft_itoall(va_arg(*args, size_t));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_intmaxt_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;

	res = ft_itoall(va_arg(*args, intmax_t));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_uintmaxt_type(t_format *infos, va_list *args)
{
	char *res;
	(void)infos;

	res = ft_itoaull(va_arg(*args, uintmax_t));
	ft_putstr(res);
	return (ft_strlen(res));
}

int display_format(t_format *infos, va_list *args)
{
	if (!(infos->type))
		return 0;

	if (infos->type == 'i' || infos->type == 'd' || infos->type == 'D')
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
	else if (infos->type == 'u')
	{
		if (infos->modifier)
		{
			if (ft_strcmp(infos->modifier, "l") == 0)
				return display_ulong_type(infos, args);
			if (ft_strcmp(infos->modifier, "ll") == 0)
				return display_ulonglong_type(infos, args);
			if (ft_strcmp(infos->modifier, "j") == 0)
				return display_uintmaxt_type(infos, args);
			if (ft_strcmp(infos->modifier, "z") == 0)
				return display_sizet_type(infos, args);
			if (ft_strcmp(infos->modifier, "h") == 0)
				return display_ushort_type(infos, args);
		}
		return (display_uint_type(infos, args));
	}
	else if (infos->type == 's')
		return display_string_type(infos, args);
	else if (infos->type == 'X' || infos->type == 'x')
		return display_base_type(infos, args, 16, infos->type == 'X');
	else if (infos->type == 'o' || infos->type == 'O')
	{
		if (infos->modifier)
		{
			if (ft_strcmp(infos->modifier, "l") == 0)
				return display_base_type_val(infos, va_arg(*args, unsigned long), 8, FALSE);
			if (ft_strcmp(infos->modifier, "ll") == 0)
				return display_base_type_val(infos, va_arg(*args, unsigned long long), 8, FALSE);
			if (ft_strcmp(infos->modifier, "z") == 0)
				return display_base_type_val(infos, va_arg(*args, size_t), 8, FALSE);
			if (infos->type == 'O' && ft_strcmp(infos->modifier, "h") == 0)
				return display_base_type_val(infos, (unsigned short)va_arg(*args, long), 8, FALSE);
			if (ft_strcmp(infos->modifier, "h") == 0)
				return display_base_type_val(infos, va_arg(*args, unsigned long), 8, FALSE);
			if (ft_strcmp(infos->modifier, "j") == 0)
				return display_base_type_val(infos, va_arg(*args, uintmax_t), 8, FALSE);
		}
		return display_base_type(infos, args, 8, FALSE);
	}
	else if (infos->type == 'c')
		return display_char_type(infos, args);
	return (0);
}
