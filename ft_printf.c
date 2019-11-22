/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:01:17 by daprovin          #+#    #+#             */
/*   Updated: 2019/11/22 16:52:19 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "printf.h"

static int	ft_isnotthetype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
				|| c == 'x' || c == 'X')
		return (0);
	return (1);
}

static void	ft_makevalues(const char *format, t_form *info)
{
	int dot;

	info->just = 0;
	info->prec = 0;
	dot = 0;
	while (ft_isnotthetype(*format))
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

static int	ft_makeinfo(const char *format, t_form *info)
{
	int i;

	i = 0;
	ft_makevalues(format, info);
	while (ft_isnotthetype(*format))
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
	return (i);
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

static void ft_printchar(t_form *info, va_list args)
{
	int just;
	char c;

	if (info->flag & FLAG_STAR)
		info->just = va_arg(args, int);
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
	}//estabas por aqui melon, deberias leer las flags del bonus para no tener
	//que cambiarlo todo despues.
	//
	//Asegurate de que las flags no hacen nada raro en ningun orden.
}

static void	ft_printtype(t_form *info, va_list args)
{
	if (info->type == 'c')
		ft_printchar(info, args);
	else if (info->type == 's'){}
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
			format = format + ft_makeinfo(format, &info) + 1;
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
	ft_printf(":%10*c:", 10, 'a');
	return (0);
}
