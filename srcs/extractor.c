/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extractor.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 14:55:36 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 14:55:39 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
 ** Setup flags of the format.
 ** Resize str.
*/
static void check_flags(char **str, t_format **format)
{
    t_bool flag_found;

    flag_found = TRUE;
    if (!str)
        return;
    if (**str == '-')
        (*format)->flags->left_justify = TRUE;
    else if (**str == '0')
        (*format)->flags->padding = TRUE;
    else if (**str == '+')
        (*format)->flags->positive = TRUE;
    else if (**str == ' ')
        (*format)->flags->blank = TRUE;
    else if (**str == '#')
        (*format)->flags->diese = TRUE;
    else
        flag_found = FALSE;
    if (flag_found)
    {
        *str = resize(*str, 1);
        check_flags(str, format);
    }
}

static void check_width(char **str, int *val)
{
    int i;
    char *res;
    int y;

    if (!str)
        return;
    i = 0;
    while ((*str)[i] && ft_isdigit(((*str)[i])))
        i++;
    if (i == 0)
        return;
    res = (char *)malloc(sizeof(char) * (i + 1));
    if (!res)
        return;
    y = 0;
    while (y < i)
    {
        res[y] = (*str)[y];
        y++;
    }
    res[y] = '\0';
    *val = ft_atoi(res);
    *str = resize(*str, i);
}

static void check_modifier(char **str, t_format **format)
{
    if (!(*str))
        return;
    if (ft_strlen(*str) >= 2 && *str[0] == 'h' && *str[1] == 'h')
        (*format)->modifier = ft_strdup("hh");
    if (ft_strlen(*str) >= 2 && *str[0] == 'l' && *str[1] == 'l')
        (*format)->modifier = ft_strdup("ll");
    else if (*str[0] == 'h')
        (*format)->modifier = ft_strdup("h");
    else if (*str[0] == 'l')
        (*format)->modifier = ft_strdup("l");
    else if (*str[0] == 'j')
        (*format)->modifier = ft_strdup("j");
    else if (*str[0] == 'z')
        (*format)->modifier = ft_strdup("z");
    if (((*format)->modifier))
        *str = resize(*str, ft_strlen((*format)->modifier));
}

static void check_period(char **str, t_format **format)
{
    if (!(*str))
        return;
    if (**str == '.')
    {
        (*format)->period = TRUE;
        *str = resize(*str, 1);
    }
}

static void check_type(char **str, t_format **format)
{
    if (!(*str))
        return;
    if (**str == 's' || **str == 'S' || **str == 'p' || **str == 'd' ||
        **str == 'D' || **str == 'i' || **str == 'o' || **str == 'O' ||
        **str == 'u' || **str == 'U' || **str == 'x' || **str == 'X' ||
        **str == 'c' || **str == 'C')
    {
        (*format)->type = **str;
        *str = resize(*str, 1);
    }
}

t_format *extract(char **str)
{
    t_format *format;

    if (!(format = new_format()))
        return (NULL);
    check_flags(str, &format);
    check_width(str, &((format)->min_width));
    check_period(str, &format);
    check_width(str, &((format)->precision));
    check_modifier(str, &format);
    check_type(str, &format);

    printf("Min width : %i\n", format->min_width);
    printf("Perdiod : %i\n", format->period);
    printf("Precision : %i\n", format->precision);
    printf("Modifier : %s\n", format->modifier);
    printf("Type : %c\n", format->type);

    return (format);
}