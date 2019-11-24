/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:01:17 by daprovin          #+#    #+#             */
/*   Updated: 2019/11/24 20:36:03 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdarg.h>
#include "libft/libft.h"
#include "printf.h"
/*
static int	ft_isnotthetype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
				|| c == 'x' || c == 'X')
		return (0);
	return (1);
}

static int ft_isnothing(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
				|| c == 'x' || c == 'X' || ft_isdigit(c) || c == '-'
				|| c == '.' || c == '*')
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
		else if (*format == '0' && !(ft_isdigit(*(format - 1))))
			info->flag |= FLAG_ZERO;
		else if (*format == '.')
			info->flag |= FLAG_DOT;
		else if (*format == '*')
			info->flag |= FLAG_STAR;
		format++;
		i++;
	}
	info->type = *format;
	if (!(ft_isnotthetype(*format)))
		i++;
	else
		ft_doingjust((info->just) , ' ');
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
static void	ft_printtype(t_form *info, va_list args)
{
	if (info->type == 'c')
		ft_printchar(info, args);
	else if (info->type == 's')
		ft_printstring(info, args);
	else if (info->type == 'p'){}
	else if ((info->type == 'd') || (info->type == 'i')){}
	else if (info->type == 'u'){}
	else if (info->type == 'x'){}
	else if (info->type == 'X'){}
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	t_form	info;

	va_start(args, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format = format + ft_makeinfo(format, &info, args);
			ft_printtype(&info, args);
		}
		ft_putchar_fd(*format, 1);
		if (*format)
			format++;
	}
	va_end(args);
	return (0);
}

int		main()
{
	ft_printf("%*as \n por favor \n%*s", 20, NULL, 20, "si");
	return (0);
}
