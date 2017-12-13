/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 13:59:57 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 14:00:00 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_nb_digit(long long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void		ft_itoa_rec(char *res, long long n, int *i)
{
	if (n < 10)
	{
		res[*i] = n + '0';
		(*i)++;
	}
	else
	{
		ft_itoa_rec(res, n / 10, i);
		ft_itoa_rec(res, n % 10, i);
	}
}

char			*ft_itoa(long long n)
{
	char			*res;
	int				i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		if ((res = (char *)ft_memalloc(sizeof(char)
						* ft_nb_digit(n) + 2)) == NULL)
			return (NULL);
		res[0] = '-';
		i++;
	}
	else
	{
		if ((res = (char *)ft_memalloc(sizeof(char)
						* ft_nb_digit(n) + 1)) == NULL)
			return (NULL);
	}
	ft_itoa_rec(res, n, &i);
	res[i] = '\0';
	return (res);
}
