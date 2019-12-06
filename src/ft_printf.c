/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:01:17 by daprovin          #+#    #+#             */
/*   Updated: 2019/12/06 19:02:50 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdarg.h>
#include "../libft/libft.h"
#include "../printf.h"
/*
static int	ft_isnotthetype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
				|| c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

static int ft_isnothing(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
				|| c == 'x' || c == 'X' || ft_isdigit(c) || c == '-'
				|| c == '.' || c == '*' || c == '%')
		return (1);
	return (0);
}

static void ft_doingjust(int just, char c)
{
	int i;

	i = 0;
	while (i < just)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}
*/
static void	ft_makevalues2(const char *format, t_form *info, va_list args)
{
	while (ft_isnotthetype(*format) && ft_isnothing(*format))
	{
		if (*format == '*' && *(format - 1) != '.')
			info->just = va_arg(args, int);
		if (*format == '*' && *(format - 1) == '.')
			info->prec = va_arg(args, int);
		if (*format == '.' && ft_isdigit(*(format + 1)))
			info->prec = ft_atoi(format + 1);
		if (ft_isdigit(*format) && *(format - 1) != '.' 
			&& !(ft_isdigit(*(format - 1))))
			info->just = ft_atoi(format);
		format++;
	}
	if (info->just < 0)
	{
		info->flag |= FLAG_MIN;
		info->just *= -1;
	}
}

static void	ft_makevalues(const char *format, t_form *info, va_list args)
{
	int dot;

	info->just = 0;
	info->prec = 0;
	dot = 0;
	if (info->flag & FLAG_STAR)
		ft_makevalues2(format, info, args);
	else
		while (ft_isnotthetype(*format) && ft_isnothing(*format))
		{
			if (*format == '.')
				dot = 1;
			if (ft_isdigit(*format))
			{
				if (dot == 0)
					info->just = ft_atoi(format);
				else if (dot == 1)
					info->prec = ft_atoi(format);
				while (ft_isdigit(*format))
					format++;
				format--;
			}
		format++;
		}
}

static int	ft_makeinfo(const char *format, t_form *info, va_list args)
{
	int i;

	i = 0;
	while (ft_isnotthetype(*format) && ft_isnothing(*format))
	{
		if (*format == '-')
			info->flag |= FLAG_MIN;
		else if (*format == '0' && !(ft_isdigit(*(format - 1))) 
			&& *(format - 1) != '.')
			info->flag |= FLAG_ZERO;
		else if (*format == '.')
			info->flag |= FLAG_DOT;
		else if (*format == '*')
			info->flag |= FLAG_STAR;
		format++;
		i++;
	}
	info->type = *format;
	i = (!(ft_isnotthetype(*format))) ? i + 1 : i;
	ft_makevalues(format - i + 1, info, args);
	if (info->prec < 0)
		info->flag &= (~FLAG_DOT);
	return (i);
}
/*
static void ft_printchar(t_form *info, va_list args)
{
	int just;
	char c;

	c = va_arg(args, int);
	just = info->just - 1;
	if (!(info->flag & FLAG_MIN))
	{
		ft_doingjust(just, ' ');
		ft_putchar_fd(c, 1);
	}
	if (info->flag & FLAG_MIN)
	{
		ft_putchar_fd(c, 1);
		ft_doingjust(just, ' ');
	}
}

static void	ft_printstring(t_form *info, va_list args)
{
	char *s;
	char n[] = "(null)";
	int l;
	int i;

	s = va_arg(args, char*);
	if (s == NULL)
		s = n;
	l = ft_strlen(s);
	if (info->flag & FLAG_DOT && info->prec < l)
		l = info->prec;
	if(!(info->flag & FLAG_MIN))
	{
		ft_doingjust(info->just - l, ' ');
		i = 0;
		while (i < l)
			ft_putchar_fd(s[i++], 1);
	}
	if (info->flag & FLAG_MIN)
	{
		i = 0;
		while (i < l)
			ft_putchar_fd(s[i++], 1);
		ft_doingjust(info->just - l, ' ');
	}
}
*/
/*
void	ft_printint2(int l, t_form *info, int n)
{
	int just;
	unsigned int x;

	x = n;
	if (info->prec > l)
		just = info->just - info->prec;
	else
		just = info->just - l;
	if (info->flag & FLAG_MIN)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			x = -1 * n;
		}
		ft_doingjust(info->prec - l, '0');
		if (l != 0 || x != 0)
			ft_putnbr_fd(x, 1);
		ft_doingjust(just, ' ');
	}
	else if (info->flag & FLAG_ZERO)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			x = -1 * n;
		}
		ft_doingjust(just, '0');
		ft_putnbr_fd(x, 1);
	}
	else
	{
		ft_doingjust(just, ' ');
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			x = -1 * n;
		}
		ft_doingjust(info->prec - l, '0');
		if (l != 0 || x != 0)
			ft_putnbr_fd(x, 1);
	}
}

int		ft_returnint(t_form *info, int l, int n)
{
	int r;

	r = l;
	if (info->prec > r)
		r = info->prec;
	if (info->just > r)
		r = info->just;
	if (n < 0)
		r++;
	return (r);
}

int		ft_printint(t_form *info, va_list args)
{
	int n;
	int aux;
	int l;

	n = va_arg(args, int);
	l = 1;
	aux = n / 10;
	while (aux != 0)
	{
		aux = aux / 10;
		l++;
	}
	if (info->flag & FLAG_DOT && n == 0 && info->prec == 0)
		l = 0;
	if (n < 0)
		(info->just)--;
	if (info->flag & FLAG_ZERO && info->prec > l)
		info->flag &= (~FLAG_ZERO);
	ft_printint2(l, info, n);
	return (ft_returnint(info, l, n));
}
*/
/*
int		ft_printperc(t_form *info, va_list args)
{
	if (info->flag & FLAG_MIN)
	{
		ft_putchar_fd('%', 1);
		ft_doingjust(info->just - 1, ' ');
	}
	else if (info->flag & FLAG_ZERO)
	{
		ft_doingjust(info->just - 1, '0');
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_doingjust(info->just - 1, ' ');
		ft_putchar_fd('%', 1);
	}
	if (info->just > 1)
		return (info->just);
	return (1);
}
*/
static int	ft_printtype(t_form *info, va_list args)
{
	int i;

	i = 0;
	if (info->type == 'c')
		i = ft_printchar(info, args);
	else if (info->type == 's')
		i = ft_printstring(info, args);
	else if (info->type == 'p'){}
	else if ((info->type == 'd') || (info->type == 'i'))
		i = ft_printint(info, args);
	else if (info->type == 'u')
		i = ft_printuint(info, args);
	else if (info->type == 'x' || info->type == 'X')
		i = ft_printhex(info, args);
	else if (info->type == '%')
		i = ft_printperc(info, args);

	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	t_form	info;
	info.flag = 0;
	va_start(args, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			info.flag = 0;
			format++;
			format = format + ft_makeinfo(format, &info, args);
			i += ft_printtype(&info, args);
		}
		if (*format != '%')
		{
		ft_putchar_fd(*format, 1);
			if (*format)
			{
				i++;
				format++;
			}
		}
	}
	va_end(args);
	return (i);
}
/*
int main()
{
//	ft_printf("%05.1u\n", -45);
	printf("%x", 11);
}
*/

