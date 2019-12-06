/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_type_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:03:30 by daprovin          #+#    #+#             */
/*   Updated: 2019/12/06 19:18:41 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static void ft_putnbrbase(unsigned int n)
{
	int i;
	char c;
	char str[12];
	char base[17];
}

int		ft_printhex(t_form *info, va_list args)
{
	unsigned int	n;
	int				aux;
	int				l;

	n = va_arg(args, unsigned int);
	l = 1;
	aux = n / 16;
	while (aux != 0)
	{
		aux = aux / 16;
		l++;
	}
	if (info->flag & FLAG_DOT && n == 0 && info->prec == 0)
		l = 0;
	if (info->flag & FLAG_ZERO && info->flag & FLAG_DOT)
		info->flag &= (~FLAG_ZERO);
	if (info->type == 'x')
		ft_printhex2(l, info, n);
	else
		ft_printHEX(l, info, n);
	return (ft_returnhex(info, l));
}
