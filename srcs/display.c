/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <htaillef@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 19:35:21 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 18:52:10 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char *process_type_with_modifier(t_format *infos, va_list *args)
{
	void *value;

	value = va_arg(*args, void *);
	if (infos->type == '%')
		return (ft_strdup("%"));
	if (infos->type == 'i' || infos->type == 'd' || infos->type == 'D')
		return (process_int(infos, value));
	if (infos->type == 'u' || infos->type == 'U')
		return (process_uint)(infos, value);
	if (infos->type == 'S' || (infos->type == 's' && infos->modifier && ft_strcmp(infos->modifier, "l") == 0))
		return (process_wstr(value));
	if (infos->type == 's')
		return (process_string(value));
	if (infos->type == 'X' || infos->type == 'x')
		return (process_hexa(infos, value));
	if (infos->type == 'o' || infos->type == 'O')
		return (process_octal(infos, value));
	if (infos->type == 'C' || (infos->type == 'c' && infos->modifier && ft_strcmp(infos->modifier, "l") == 0))
		return (process_wchar(value));
	if (infos->type == 'c')
		return (process_char(value));
	if (infos->type == 'p')
		return (ft_itoall_base((long)value, 16, FALSE));
	return (ft_strdup(""));
}

/*
 ** Put in add buffer string according to format flags.
*/

void process_add_buffer(char **add, t_format *format, char *res)
{
	if (format->flags->blank && !(format->flags->positive)) // ' '
	{
		if (format->is_numeric && !(format->is_negative) && (format->type == 'D' || format->type == 'd' || format->type == 'i'))
			*add = ft_strdup(" ");
	}
	if (format->flags->positive && format->is_numeric && (format->type == 'D' || format->type == 'd' || format->type == 'i')) // '+'
	{
		if (!(format->is_negative))
			*add = ft_strdup("+");
	}
	if (format->is_numeric && format->is_negative)
		*add = ft_strdup("-");
	if (format->flags->diese && format->is_numeric) // '#'
	{
		if (ft_strcmp(res, "0") != 0 && ft_strlen(res) > 0)
		{
			if (format->type == 'x')
				*add = ft_strdup("0x");
			if (format->type == 'X')
				*add = ft_strdup("0X");
			if (format->type == 'o' || format->type == 'O')
				*add = ft_strdup("0");
		}	
	}
	if (format->type == 'p')
		*add = ft_strdup("0x");
}

/*
 ** Makes res buffer bigger or smaller according to format precision.
*/

void process_precision(char **res, t_format *format)
{
	char *res1;
	char *ret;
	
	if (format->is_numeric && format->precision > 0)
	{	
		while (ft_strlen(*res) < format->precision)
		{
			ret = *res;
			*res = ft_strjoin("0", *res);
			ft_memdel((void **)&ret);
		}
	}
	else if (format->precision > 0 && (format->type == 's' || format->type == 'S'))
	{
		res1 = (char *)ft_memalloc(format->precision + 1);
		ft_strncpy(res1, *res, format->precision);
		*res = res1;
	}
}

/*
 ** Inits final buffer with correct size and char according to format flags padding and width
*/

t_bool process_final(char **final, char *res, t_format *format, char *add)
{
	int addlen;
	size_t reslen;

	reslen = format->type == 'c' ? 1 : ft_strlen(res);
	addlen = add != NULL ? ft_strlen(add) : 0;
	
	if (reslen + addlen < format->min_width)
	{
		if (format->type == 'c' && ft_strcmp(res, "^@") == 0)
		{
			if (format->flags->padding && !format->flags->left_justify)
				*final = ft_init(format->min_width + 1, '0');
			else
				*final = ft_init(format->min_width + 1, ' ');
		}
		else if (format->flags->padding && !format->flags->left_justify && !(format->is_numeric && format->period)) // '0'
			*final = ft_init(format->min_width, '0');
		else
		{
			if (!format->type)
				*final = ft_init(ft_strlen(res) > 0 ? format->min_width : format->min_width - 1, ' ');
			else
				*final = ft_init(format->min_width, ' ');
		}
		return (FALSE);
	}
	else
	{
		if (add)
			*final = ft_strjoin(add, res);
		else
			*final = ft_strdup(res);
		return (TRUE);
	}
}

/*
 ** Joins add and res buffer in final buffer according to format left justify or padding
*/

void process_justify(char **final, t_format *format, char *add, char *res)
{
	int add_insert = -1;
	int	res_insert = -1;

	if (format->period && format->precision == 0 && format->type == 's')
		return;
	
	if (format->flags->padding && !(format->flags->left_justify) && !(format->is_numeric && format->period))
	{
		if (add)
			add_insert = 0;
		res_insert = ft_strlen(*final) - ft_strlen(res);
	}
	else if (format->flags->padding && !(format->flags->left_justify) && format->precision > 0)
	{
		if (add)
			add_insert = ft_strlen(*final) - format->precision - ft_strlen(add);
		res_insert = ft_strlen(*final) - ft_strlen(res);
	}
	else if (format->flags->left_justify)
	{
		if (add)
			add_insert = 0;
		res_insert = add != NULL ? ft_strlen(add) : 0;
	}
	else
	{	
		if (add)	
			add_insert = ft_strlen(*final) - ft_strlen(res) - ft_strlen(add);
		res_insert = ft_strlen(*final) - ft_strlen(res);
	}
	
	if (add && add_insert != -1)	
		ft_write(final, add, add_insert);
	if (res_insert != -1)
		ft_write(final, res, res_insert);
}

char	*process_flags_and_precision(char *res, t_format *format)
{
	char *final;
	char *add;

	final = NULL;
	add = NULL;
	process_add_buffer(&add, format, res);
	if (format->period && format->precision == 0 && (ft_strcmp(res, "0") == 0 || (format->type == 's' || format->type == 'S'))){
		if (!(format->flags->diese && (format->type == 'o' || format->type == 'O')))
			res = ft_strdup("");
	}
	process_precision(&res, format);
	
	if (process_final(&final, res, format, add))
	{
		ft_memdel((void **)&add);
		ft_memdel((void**)&res);
		return (final);
	}
	process_justify(&final, format, add, res);
	ft_memdel((void **)&add);
	ft_memdel((void **)&res);
	return (final);
}

int		display_format(t_format *infos, va_list *args)
{
	char *res;
	char *final;
	int len;
	t_bool isnull;

	if (!(res = process_type_with_modifier(infos, args)))
		return (-1);
	isnull = ft_strcmp(res, "^@") == 0;
	if (res[0] == '-' && infos->is_numeric)
	{
		res = ft_strsub(res, 1, ft_strlen(res) - 1);
		infos->is_negative = TRUE;
	}
	if (!(final = process_flags_and_precision(res, infos)))
		return (0);
	if (isnull)
		customput(final);
	else
		ft_putstr(final);
	len = ft_strlen(final);
	ft_memdel((void **)&final);
	return (isnull ? len - 1 : len);
}
