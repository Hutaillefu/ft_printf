/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_manip.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 15:10:48 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:10:51 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
 ** Remove n char from str.
*/
char    *resize(char *str, int n)
{
    char    *res;
    if (!str || n == 0)
    {
        printf("Resize error\n");
        return (NULL);
    }
    res = ft_strsub(str, n, ft_strlen(str) - n);
    if (!res)
    {
        printf("Resize error\n");
        return (NULL);
    }
    return (res);
}