/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 15:58:09 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 15:58:14 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void process(char **format, va_list *args)
{
    (void)args;
    int i;
    t_format *infos;

    i = 0;
    while ((*format)[i])
    {
        if ((*format)[i] == '%')
        {
            display(*format, i); // affiche le text avant le %
            if ((*format)[i + 1] && (*format)[i + 1] == '%')
            {
                *format = resize(*format, i);
                ft_putchar('%');
                *format = resize(*format, 2);
                i = 0;
            }
            else
            {
                *format = resize(*format, i + 1); // supprime le text et le %
                infos = extract(format);          // extrait les infos du %
                i = 0;
                display_format(infos, args);       // affiche le format
                // clear_infos(&infos);            // supprime la structure
            }
            continue;
        }
        i++;
    }
    ft_putstr(*format);
}

int ft_printf(const char *restrict format, ...)
{
    if (!format)
        return (-1);

    va_list args;
    va_start(args, format);

    process((char **)&format, &args);

    va_end(args);
    return (0);
}
