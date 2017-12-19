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

char *process_type_with_modifier(t_format *infos, va_list *args)
{
	void *value;
	char *res;

	value = va_arg(*args, void *);

	if (infos->type == 'i' || infos->type == 'd' || infos->type == 'D')
	{
		if (infos->modifier)
		{
			if (ft_strcmp(infos->modifier, "l") == 0)
				return ft_itoall((long)value);
			if (ft_strcmp(infos->modifier, "ll") == 0)
				return ft_itoall((long long)value);
			if (ft_strcmp(infos->modifier, "z") == 0)
				return ft_itoaull((size_t)value);
			if (ft_strcmp(infos->modifier, "j") == 0)
				return ft_itoall((intmax_t)value);
			if (ft_strcmp(infos->modifier, "hh") == 0 && infos->type == 'D')
				return ft_itoall((long)value);
			if (ft_strcmp(infos->modifier, "hh") == 0)
				return ft_itoall((char)value);
		}
		if (infos->type == 'D')
			return ft_itoall((long)value);
		return ft_itoall((int)value); // modifier h or hh call int
	}
	else if (infos->type == 'u' || infos->type == 'U')
	{
		if (infos->modifier)
		{
			if (ft_strcmp(infos->modifier, "l") == 0)
				return ft_itoaull((unsigned long)value);
			if (ft_strcmp(infos->modifier, "ll") == 0)
				return ft_itoaull((unsigned long long)value);
			if (ft_strcmp(infos->modifier, "j") == 0)
				return ft_itoaull((uintmax_t)value);
			if (ft_strcmp(infos->modifier, "z") == 0)
				return ft_itoaull((size_t)value);
			if (ft_strcmp(infos->modifier, "h") == 0)
				return ft_itoaull((unsigned short)value);
			if (ft_strcmp(infos->modifier, "hh") == 0 && infos->type == 'U')
				return ft_itoaull((unsigned long)value);
			if (ft_strcmp(infos->modifier, "hh") == 0)
				return ft_itoaull((unsigned char)value);
		}
		if (infos->type == 'U')
			return ft_itoaull((unsigned long)value);
		return ft_itoaull((unsigned int)value);
	}
	else if (infos->type == 's')
	{
		res = (char *)value;
		if (!res)
			return ft_strdup("(null)");
		return (res);
	}
	else if (infos->type == 'X' || infos->type == 'x')
	{
		if (infos->modifier)
		{
			if (ft_strcmp(infos->modifier, "l") == 0)
				return ft_itoaull_base((unsigned long)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "ll") == 0)
				return ft_itoaull_base((unsigned long long)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "z") == 0)
				return ft_itoaull_base((size_t)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "h") == 0)
				return ft_itoall_base((unsigned short)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "h") == 0)
				return ft_itoaull_base((unsigned long)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "hh") == 0)
				return ft_itoaull_base((unsigned char)value, 16, infos->type == 'X');
			if (ft_strcmp(infos->modifier, "j") == 0)
				return ft_itoaull_base((uintmax_t)value, 16, infos->type == 'X');
		}
		return ft_itoaull_base((unsigned int)value, 16, infos->type == 'X');
	}
	else if (infos->type == 'o' || infos->type == 'O')
	{
		if (infos->modifier)
		{
			if (ft_strcmp(infos->modifier, "l") == 0)
				return ft_itoaull_base((unsigned long)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "ll") == 0)
				return ft_itoaull_base((unsigned long long)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "z") == 0)
				return ft_itoaull_base((size_t)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "h") == 0)
				return ft_itoall_base((unsigned short)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "h") == 0)
				return ft_itoaull_base((unsigned long)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "j") == 0)
				return ft_itoaull_base((uintmax_t)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "hh") == 0 && infos->type == 'O')
				return ft_itoaull_base((unsigned long)value, 8, FALSE);
			if (ft_strcmp(infos->modifier, "hh") == 0)
				return ft_itoaull_base((unsigned char)value, 8, FALSE);
		}
		if (infos->type == 'O')
			return ft_itoall_base((long)value, 8, FALSE);
		return ft_itoall_base((unsigned int)value, 8, FALSE);
	}
	else if (infos->type == 'c')
	{
		res = ft_strdup("");
		res[0] = (unsigned char)value;
		return (res);
	}
	else if (infos->type == 'p')
		return ft_strjoin("0x", ft_itoall_base((long)value, 16, FALSE));
	return (NULL);
}

/*char *process_flags_and_precision(char *res, t_format *format)
{
	char *final;


}*/

int display_format(t_format *infos, va_list *args)
{
	char *res;
	//char *final;
	int len;

	if (!(infos->type))
		return 0;

	res = process_type_with_modifier(infos, args);
	if (!res)
		return (0);
	if (res[0] == 0)
	{
		ft_putchar(0);
		return (1);
	}

	//final = process_flags_and_precision(res, infos);
	//if (!final)
	//	return (0);

	ft_putstr(res);
	/*len = ft_strlen(final);

	free(res);
	free(final);*/

	len = ft_strlen(res);
	return (len);
}
