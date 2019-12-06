/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnmbrbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daprovin <daprovin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:48:49 by daprovin          #+#    #+#             */
/*   Updated: 2019/12/06 18:53:44 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

int main(int argn, char **argv)
{
	int n;
	int aux;
	int i;
	char c;
	char str[12];
	char base[17];

	ft_memcpy(base, "0123456789abcdef", 16);
	base[16] = '\0';
	if (argn == 1)
		return (0);
	n = ft_atoi(argv[1]);
	i = 0;
	aux = n;
	while (aux != 0)
	{
		aux = aux / 16;
		i++;
	}
	ft_printf("length=%d\n", i);
	i = 0;
	if (n == 0)
		str[i++] = '0';
	while (n != 0)
	{
		str[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	str[i] = '\0';
	i = 0;
	while (ft_strlen(str) / 2 - i > 0)
	{
		c = str[i];
		str[i] = str[ft_strlen(str) - i - 1];
		str[ft_strlen(str) - i - 1] = c;
		i++;
	}
	ft_putstr_fd(str, 1);
	return (0);
}
