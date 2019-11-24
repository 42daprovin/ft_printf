/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:10:42 by daprovin          #+#    #+#             */
/*   Updated: 2019/11/24 20:14:14 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

void	ft_printchar(t_form *info, va_list args)
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

void	ft_printstring(t_form *info, va_list args)
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
