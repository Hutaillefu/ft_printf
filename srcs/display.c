/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <htaillef@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 19:35:21 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 14:02:46 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
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

static char *process_int(t_format *infos, void *value)
{
	t_type type;

	type.t_intmax_t = (intmax_t)value;
	if (infos->modifier)
	{
		if (ft_strcmp(infos->modifier, "l") == 0)
			return ft_itoall(type.t_long);
		else if (ft_strcmp(infos->modifier, "ll") == 0)
			return ft_itoall(type.t_long_long);
		else if (ft_strcmp(infos->modifier, "z") == 0)
			return ft_itoall((ssize_t)value);
		else if (ft_strcmp(infos->modifier, "j") == 0)
			return ft_itoall(type.t_intmax_t);
		else if (ft_strcmp(infos->modifier, "hh") == 0 && infos->type == 'D')
			return ft_itoall(type.t_long);
		else if (ft_strcmp(infos->modifier, "hh") == 0)
			return ft_itoall((type.t_char));
		else if (ft_strcmp(infos->modifier, "h") == 0 && infos->type == 'D')
			return ft_itoall(type.t_long);
		else if (ft_strcmp(infos->modifier, "h") == 0)
			return ft_itoall((type.t_short));
	}
	if (infos->type == 'D')
		return ft_itoall(type.t_long);
	else return ft_itoall(type.t_int);
}

static char *process_uint(t_format *infos, void *value)
{
	if (infos->modifier)
	{
		if (ft_strcmp(infos->modifier, "l") == 0)
			return ft_itoaull((unsigned long)value);
		if (ft_strcmp(infos->modifier, "ll") == 0)
			return ft_itoaull((unsigned long long)value);
		if (ft_strcmp(infos->modifier, "j") == 0)
			return ft_itoaull((uintmax_t)value);
		if (ft_strcmp(infos->modifier, "z") == 0)
			return ft_itoaull((size_t)value);
		if (ft_strcmp(infos->modifier, "h") == 0 && infos->type == 'U')
			return ft_itoaull((unsigned long)value);
		if (ft_strcmp(infos->modifier, "h") == 0)
			return ft_itoaull((unsigned short)value);
		if (ft_strcmp(infos->modifier, "hh") == 0 && infos->type == 'U')
			return ft_itoaull((unsigned long)value);
		if (ft_strcmp(infos->modifier, "hh") == 0)
			return ft_itoaull((unsigned char)value);
	}
	if (infos->type == 'U')
		return ft_itoaull((unsigned long)value);
	return ft_itoaull((unsigned int)value);
}

static char *process_string(void *value)
{
	char *res;

	res = (char *)value;
	if (!res)
		return ft_strdup("(null)");
	res = ft_strdup(res);
	return (res);
}

static char *process_hexa(t_format *infos, void *value)
{
	if (infos->modifier)
	{
		if (ft_strcmp(infos->modifier, "l") == 0)
			return ft_itoaull_base((unsigned long)value, 16, infos->type == 'X');
		if (ft_strcmp(infos->modifier, "ll") == 0)
			return ft_itoaull_base((unsigned long long)value, 16, infos->type == 'X');
		if (ft_strcmp(infos->modifier, "z") == 0)
			return ft_itoaull_base((size_t)value, 16, infos->type == 'X');
		if (ft_strcmp(infos->modifier, "h") == 0)
			return ft_itoall_base((unsigned short)value, 16, infos->type == 'X');
		if (ft_strcmp(infos->modifier, "h") == 0)
			return ft_itoaull_base((unsigned long)value, 16, infos->type == 'X');
		if (ft_strcmp(infos->modifier, "hh") == 0)
			return ft_itoaull_base((unsigned char)value, 16, infos->type == 'X');
		if (ft_strcmp(infos->modifier, "j") == 0)
			return ft_itoaull_base((uintmax_t)value, 16, infos->type == 'X');
	}
	return ft_itoaull_base((unsigned int)value, 16, infos->type == 'X');
}

static char *process_octal(t_format *infos, void *value)
{
	if (infos->modifier)
	{
		if (ft_strcmp(infos->modifier, "l") == 0)
			return ft_itoaull_base((unsigned long)value, 8, FALSE);
		if (ft_strcmp(infos->modifier, "ll") == 0)
			return ft_itoaull_base((unsigned long long)value, 8, FALSE);
		if (ft_strcmp(infos->modifier, "z") == 0)
			return ft_itoaull_base((size_t)value, 8, FALSE);
		if (ft_strcmp(infos->modifier, "h") == 0)
			return ft_itoall_base((unsigned short)value, 8, FALSE);
		if (ft_strcmp(infos->modifier, "h") == 0)
			return ft_itoaull_base((unsigned long)value, 8, FALSE);
		if (ft_strcmp(infos->modifier, "j") == 0)
			return ft_itoaull_base((uintmax_t)value, 8, FALSE);
		if (ft_strcmp(infos->modifier, "hh") == 0 && infos->type == 'O')
			return ft_itoaull_base((unsigned long)value, 8, FALSE);
		if (ft_strcmp(infos->modifier, "hh") == 0)
			return ft_itoaull_base((unsigned char)value, 8, FALSE);
	}
	if (infos->type == 'O')
		return ft_itoaull_base((unsigned long)value, 8, FALSE);
	return ft_itoall_base((unsigned int)value, 8, FALSE);
}

static char *process_char(void *value)
{
	char *res;
	
	if ((unsigned char)value == 0)
		res = ft_strdup("^@");
	else
	{
		res = ft_memalloc(2);
		res[0] = (unsigned char)value;
		res[1] = '\0';
	}
	return (res);
}

static char *process_wchar_real(wchar_t c)
{
	char *res;

	if (c == 0)
		res = ft_strdup("^@");
	else 
		res = wchartostr(c);
	return (res);
}

static char *process_wchar(void *value)
{
	wchar_t	c;
	
	c = (wchar_t)value;
	return (process_wchar_real(c));
}

static char *process_wstr(void * value)
{
	wchar_t *wstr;
	char	*res;
	char	*ret;
	char	*wchar;

	wstr = (wchar_t *)value;
	if (!wstr)
		return (ft_strdup("(null)"));
	res = ft_strdup("");
	while (*wstr)
	{
		ret = res;
		wchar = process_wchar_real(*wstr);
		res = ft_strjoin(res, wchar);
		ft_memdel((void **)&ret);
		ft_memdel((void **)&wchar);
		wstr++;
	}
	return (res);
}

char *process_type_with_modifier(t_format *infos, va_list *args)
{
	void *value;

	value = va_arg(*args, void *);

	if (infos->type == '%')
		return ft_strdup("%");
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
		return ft_itoall_base((long)value, 16, FALSE);
	return (ft_strdup(""));
}

char *ft_init(size_t len, char c)
{
	char *res;
	size_t i;

	res = ft_memalloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = c;
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
 ** Puts new in src at start_index
*/
void ft_write(char **src, char *new, size_t start_index)
{
	size_t y;

	y = 0;
	while (y < ft_strlen(new))
	{
		(*src)[start_index + y] = new[y];
		y++;
	}
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
	
	if (format->flags->padding && !format->flags->left_justify && format->period && format->precision == 0)
	 {
		 if (format->type == 'c' && ft_strcmp(res, "^@") == 0)
			 *final = ft_init(format->min_width + 1, '0');
		else 
			 *final = ft_init(format->min_width, '0');						
 		return FALSE;
	 }

	reslen = format->type == 'c' ? 1 : ft_strlen(res);
	addlen = add != NULL ? ft_strlen(add) : 0;
	if (reslen + addlen < format->min_width)
	{
		if (format->type == 'c' && ft_strcmp(res, "^@") == 0)
		{
			if (format->flags->padding)
				*final = ft_init(format->min_width + 1, '0');
			else
				*final = ft_init(format->min_width + 1, ' ');	
		}
		else if (format->flags->padding && !format->flags->left_justify && format->precision == 0) // '0'
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
	int addlen;
	int reslen;

	/*if (format->type == 'c' || format->type == 'C')
		reslen = ft_strcmp(res, "^@") == 0 ? 1 : ft_strlen(res);
	else */
		reslen = ft_strlen(res);
	if (format->period && format->precision == 0 && format->type == 's')
		return;
	addlen = add != NULL ? ft_strlen(add) : 0;
	if (format->flags->padding && !(format->flags->left_justify) && format->precision == 0)
	{
		if (add)
			ft_write(final, add, 0);
		ft_write(final, res, ft_strlen(*final) - reslen);
	}
	else if (format->flags->padding && !(format->flags->left_justify) && format->precision > 0)
	{
		if (add)
			ft_write(final, add, ft_strlen(*final) - format->precision - ft_strlen(add));
		ft_write(final, res, ft_strlen(*final) - ft_strlen(res));
	}
	else if (format->flags->left_justify)
	{
		if (add)
			ft_write(final, add, 0);
		ft_write(final, res, addlen);
	}
	else if (!(format->flags->left_justify) && !(format->flags->padding))
	{	
		if (add)	
			ft_write(final, add, ft_strlen(*final) - ft_strlen(res) - ft_strlen(add));
		ft_write(final, res, ft_strlen(*final) - ft_strlen(res));
	}
}

char *process_flags_and_precision(char *res, t_format *format)
{
	char *final;
	char *add;
	int addlen;

	final = NULL;
	add = NULL;
	process_add_buffer(&add, format, res);
	if (format->period && format->precision == 0 && ft_strcmp(res, "0") == 0){
		if (format->flags->diese && (format->type == 'o' || format->type == 'O'))
		{}
		else
		{
		res = ft_strdup("");
		}
	}
	addlen = add != NULL ? ft_strlen(add) : 0;
	process_precision(&res, format);
	if (process_final(&final, res, format, add))
	{
		ft_memdel((void **)&add);
		ft_memdel((void**)&res);
		return (final);
	}
	//printf("%s\n", final);
	process_justify(&final, format, add, res);
	ft_memdel((void **)&add);
	ft_memdel((void **)&res);
	return (final);
}

void	customput(char *final)
{
	int i = 0;
	char c = 0;

	while (final[i])
	{
		if (final[i] == '^' && final[i + 1] && final[i + 1] == '@')
		{
			write(1, &c, 1);
			i++;
		}
		else
			ft_putchar(final[i]);
		i++;
	}
}

int display_format(t_format *infos, va_list *args)
{
	char *res;
	char *final;
	int len;
	t_bool isnull;

	res = process_type_with_modifier(infos, args);
	isnull = ft_strcmp(res, "^@") == 0;
	if (isnull && infos->type == 'c' && infos->min_width < 2)
	{
		ft_memdel((void **)&res);
		ft_putchar(0);
		return (1);
	}
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
