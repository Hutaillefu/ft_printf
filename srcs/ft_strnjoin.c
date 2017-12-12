/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 17:18:54 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 17:18:55 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (n > s2len)
		return (NULL);
	str = (char *)ft_memalloc(s1len + n + 1);
	if (!str)
		return (NULL);
	ft_strcat(str, s1);
	ft_strncat(str, s2, n);
	return (str);
}