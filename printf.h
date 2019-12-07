/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 05:48:43 by daprovin          #+#    #+#             */
/*   Updated: 2019/12/07 05:23:31 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdio.h>
# include <stdarg.h>

# define FLAG_MIN 1u
# define FLAG_ZERO 2u
# define FLAG_DOT 4u
# define FLAG_STAR 8u

typedef struct	s_form
{
	unsigned int	flag;
	int				prec;
	int				just;
	char			type;
}				t_form;

int				ft_isnotthetype(char c);
int				ft_isnothing(char c);
void			ft_doingjust(int just, char c);
int				ft_printchar(t_form *info, va_list args);
int				ft_printstring(t_form *info, va_list args);
int				ft_printperc(t_form *info, va_list args);
int				ft_printint(t_form *info, va_list args);
int				ft_printuint(t_form *info, va_list args);
int				ft_printhex(t_form *info, va_list args);
int				ft_printf(const char *format, ...);
void			ft_suport(int *i, const char **format);
int				ft_printadr(t_form *info, va_list args);

#endif
