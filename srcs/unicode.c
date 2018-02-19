/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unicode.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <htaillef@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/06 19:35:21 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 13:30:52 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		wcharlen(wchar_t wchar)
{
	if (wchar <= 0x007F)
		return (1);
	else if (wchar <= 0x0FFF)
		return (2);
	else if (wchar <= 0xFFFF)
		return (3);
	else if (wchar <= 0x10FFFF)
		return (4);
	return (-1);
}

char	*wchartostr(wchar_t wchar)
{
	int		len;
	char	*res;
	
	len = wcharlen(wchar);
	res = ft_memalloc(len + 1);
	ft_bzero(res, len + 1);
	if (len == 1)
		res[0] = wchar;
	else if (len == 2)
	{
		res[0] = (wchar >> 6) + 192;
		res[1] = (wchar & 0x3F) + 128;
	}
	else if (len == 3)
	{
		res[0] = ((wchar >> 12) & 0x3F) + 224;
		res[1] = ((wchar >> 6) & 0x3F) + 128;
		res[2] = (wchar & 0x3F) + 128;
	}
	else if (len == 4)
	{
		res[0] = ((wchar >> 18) & 0x3F) + 240;
		res[1] = ((wchar >> 12) & 0x3F) + 128;
		res[2] = ((wchar >> 6) & 0x3F) + 128;
		res[3] = (wchar & 0x3F) + 128;
	}
	return (res);
}
	
	