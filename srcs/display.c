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

void display_short_type(t_format *infos, va_list *args, char **buffer)
{
	(void)infos;
	*buffer = ft_strjoin(*buffer, ft_itoa(va_arg(*args, int)));
}

void display_int_type(t_format *infos, va_list *args, char **buffer)
{
	if (!infos->modifier)
		*buffer = ft_strjoin(*buffer, ft_itoa(va_arg(*args, int)));
	else if (infos->modifier && ft_strcmp(infos->modifier, "h") == 0)
		display_short_type(infos, args, buffer);
}

void display_string_type(t_format *infos, va_list *args, char **buffer)
{
	(void)infos;
	*buffer = ft_strjoin(*buffer, va_arg(*args, char *));
}

void display_base_type(t_format *infos, va_list *args, char **buffer, int base, t_bool capital)
{
	(void)infos;
	*buffer = ft_strjoin(*buffer, ft_itoa_base(va_arg(*args, int), base, capital));
}

void display_format(t_format *infos, va_list *args, char **buffer)
{
	if (!(infos->type))
		return;
	if (infos->type == 'i' || infos->type == 'd')
		display_int_type(infos, args, buffer);
	else if (infos->type == 's')
		display_string_type(infos, args, buffer);
	else if (infos->type == 'X')
		display_base_type(infos, args, buffer, 16, TRUE);
	else if (infos->type == 'x')
		display_base_type(infos, args, buffer, 16, FALSE);
	else if (infos->type == 'o')
		display_base_type(infos, args, buffer, 8, FALSE);
}
