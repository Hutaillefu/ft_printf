/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   retrieve_data.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 15:44:16 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 15:44:19 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

short   get_short(va_list *args)
{
    return ((short)va_arg(args, int));
}

unsigned short   get_unsigned_short(va_list *args)
{
    return ((unsigned short)va_arg(args, int));
}

int   get_int(va_list *args)
{
    return (va_arg(args, int));
}

int   get_unsigned_int(va_list *args)
{
    return ((unsigned int)va_arg(args, int));
}

int   get_char(va_list *args)
{
    return ((char)va_arg(args, int));
}





