/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:01:17 by daprovin          #+#    #+#             */
/*   Updated: 2019/11/22 10:15:31 by daprovin         ###   ########.fr       */
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

static void	ft_makevalues(const char **format, t_form *info)
{
	
}

static int	ft_makeinfo(const char **format, t_form *info)
{
	int i;

	i = 0;
	(*format)++;
	ft_makevalues(format, info);
	while (ft_isnotthetype(**format))
	{
		if (**format == '-')
			a.flag |= FLAG_MIN;
		else if (**format == '0')
			a.flag |= FLAG_ZERO;
		else if (**format == '.')
			a.flag |= FLAG_DOT;
		else if (**format == '*')
			a.flag |= FLAG_STAR;
	}

	return (i);
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
			format = format + ft_makeinfo(&format, &info);
			//primero mirar las flags y despues ver el tipo, cada tipo tendra
			//su funcion.
		}
		ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

int		main()
{
	ft_printf("hola %me llamo %david");
	return (0);
}
