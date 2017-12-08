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

void display_short_type(t_format *infos, va_list *args)
{
	(void)infos;
	ft_putnbr(va_arg(*args, int));
}

void display_int_type(t_format *infos, va_list *args)
{
	if (!infos->modifier)
		ft_putnbr(va_arg(*args, int));
	else if (infos->modifier && ft_strcmp(infos->modifier, "h") == 0)
		display_short_type(infos, args);
}

void display_format(t_format *infos, va_list *args)
{
	if (infos->type && (infos->type == 'i' || infos->type == 'd'))
		display_int_type(infos, args);
}
