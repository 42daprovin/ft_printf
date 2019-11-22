/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 05:48:43 by daprovin          #+#    #+#             */
/*   Updated: 2019/11/22 10:14:23 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define FLAG_MIN (1<<0)
# define FLAG_ZERO (1<<1)
# define FLAG_DOT (1<<2)
# define FLAG_STAR (1<<3)

typedef struct	s_form
{
	unsigned int	flag;
	int				prec;
	int				justif;
	char			type;
}				t_form;

#endif
