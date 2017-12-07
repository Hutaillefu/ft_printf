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
void    display(const char *str, int n)
{
    int i;
    if (!str || n <= 0)
        return ;
    i = 0;
    while (str[i] && i < n)
    {
        ft_putchar(str[i]);
        i++;
    }
}

