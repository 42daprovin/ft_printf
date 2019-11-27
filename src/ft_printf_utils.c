/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:44:14 by daprovin          #+#    #+#             */
/*   Updated: 2019/11/27 05:21:00 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf.h"

int		ft_isnotthetype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
				|| c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

int		ft_isnothing(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
				|| c == 'x' || c == 'X' || ft_isdigit(c) || c == '-'
				|| c == '.' || c == '*' || c == '%')
		return (1);
	return (0);
}

void	ft_doingjust(int just, char c)
{
	int i;

	i = 0;
	while (i < just)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}
