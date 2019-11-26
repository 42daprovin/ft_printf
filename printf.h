/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 05:48:43 by daprovin          #+#    #+#             */
/*   Updated: 2019/11/26 00:19:35 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdio.h>
# include <stdarg.h>

# define FLAG_MIN (1u<<0u)
# define FLAG_ZERO (1u<<1u)
# define FLAG_DOT (1u<<2u)
# define FLAG_STAR (1u<<3u)

typedef struct	s_form
{
	unsigned int	flag;
	int				prec;
	int				just;
	char			type;
}				t_form;

int		ft_isnotthetype(char c);
int		ft_isnothing(char c);
void	ft_doingjust(int just, char c);
int		ft_printchar(t_form *info, va_list args);
int		ft_printstring(t_form *info, va_list args);
void	ft_printstring2(char *s, int l, t_form *info);
int		ft_printperc(t_form *info, va_list args);

#endif
