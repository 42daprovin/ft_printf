/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corozco <corozco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:31:05 by corozco           #+#    #+#             */
/*   Updated: 2019/11/27 05:10:05 by daprovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	ac = 0;
	av = NULL;

//	pruebas char

	printf ("\033[33;01m	Pruebas \033[32;01mChar \033[00m\n");

	printf("=========================\n");
	printf("		(1) Prueba char [c]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%c]\n", 'c'));
	printf("valeur de retour = [%d]\n", printf("   printf = [%c]\n", 'c'));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(2) Prueba char [*c] {12} et [*c] {-12}\n");
	printf("valeur de retour = [%d] et [%d]\n", ft_printf("ft_printf = [%*c] ", 12, 'c'), ft_printf("|| ft_printf(2) = [%*c]\n", -12, 'c'));
	printf("valeur de retour = [%d] et [%d]\n", printf("   printf = [%*c] ", 12, 'c'), printf("||    printf(2) = [%*c]\n", -12, 'c'));
	printf("=========================\n");


	printf("=========================\n");
	printf("		(3) Prueba char [-40c]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-40c]\n", 'c'));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-40c]\n", 'c'));
	printf("=========================\n");


	printf("=========================\n");
	printf("		(4) Prueba char [-*c] {40} (mirar con -40)\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-*c]\n", 40, 'c'));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-*c]\n", 40, 'c'));
	printf("=========================\n");


	printf("=========================\n");
	printf("		(5) Prueba char [-*.c] {0}\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-*.c]\n", 10, 'c'));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-*.c]\n", 10, 'c'));
	printf("=========================\n");


	printf("=========================\n");
	printf("		(6) Prueba char [0*.c] {2} no definido\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%0*.c]\n", 2, 'c'));
//	printf("valeur de retour = [%d]\n", printf("   printf = [%0*.c]\n", 2, 'c'));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(7) Prueba char [.2c] {2} no definido\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%.2c]\n", 'c'));
//	printf("valeur de retour = [%d]\n", printf("   printf = [%.2c]\n", 'c'));
	printf("=========================\n");

//	pruebas string

	printf ("\n\n\033[33;01m	Pruebas \033[32;01mString \033[00m\n");

	printf("=========================\n");
	printf("		(1) Prueba string [s]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%s]\n", "Hola como estas"));
	printf("valeur de retour = [%d]\n", printf("   printf = [%s]\n", "Hola como estas"));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(2) Prueba string [18s]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%18s]\n", "Hola como estas"));
	printf("valeur de retour = [%d]\n", printf("   printf = [%18s]\n", "Hola como estas"));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(3) Prueba string [-*s] {-22} (mirar con positivo)\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-*s]\n", -22, "Hola como estas"));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-*s]\n", -22, "Hola como estas"));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(4) Prueba string [*s] {35}\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-*.*s]\n", -10, 8,"Hola como estas"));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-*.*s]\n", -10, 8, "Hola como estas"));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(5) Prueba string [*.*s] {0,10}\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%*.*s]\n", 0, 10,"Hola como estas"));
	printf("valeur de retour = [%d]\n", printf("   printf = [%*.*s]\n", 0,  10, "Hola como estas"));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(6) Prueba string [.s]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%.s]\n", "Hola como estas"));
	printf("valeur de retour = [%d]\n", printf("   printf = [%.s]\n", "Hola como estas"));
	printf("=========================\n");

//	pruebas d integer

	printf ("\n\n\033[33;01m	Pruebas \033[32;01md \033[00m\n");

	printf("=========================\n");
	printf("		(1) Prueba numeros (d) [d]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%d] et [%d]\n", 42, -42));
	printf("valeur de retour = [%d]\n", printf("   printf = [%d] et [%d]\n", 42, -42));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(2) Prueba numeros (d) [10d]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%10d] et [%10d]\n",42, -42));
	printf("valeur de retour = [%d]\n", printf("   printf = [%10d] et [%10d]\n",42, -42));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(3) Prueba numeros (d) [10.10d]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%10.10d] et [%10.10d]\n",42, -42));
	printf("valeur de retour = [%d]\n", printf("   printf = [%10.10d] et [%10.10d]\n",42, -42));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(4) Prueba numeros (d) [-10d] y [-10.10d]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-10d] et [%-10.10d]\n",1, 35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-10d] et [%-10.10d]\n",1, 35));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(5) Prueba numeros (d) [010d] [010.4d]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%05d] et [%010.5d]\n", -12, 35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%05d] et [%010.5d]\n", -12, 35));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(6) Prueba numeros (d) [010.4d]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%010.4d]\n", 0));
	printf("valeur de retour = [%d]\n", printf("   printf = [%010.4d]\n", 0));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(7) Prueba numeros [.d] {42}{0}\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%.d] et [%.d]\n", 42, 0));
	printf("valeur de retour = [%d]\n", printf("   printf = [%.d] et [%.d]\n", 42, 0));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(8) Prueba numeros [--.*d] {5}{42}\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%--.*d]\n", 5, 42));
	printf("valeur de retour = [%d]\n", printf("   printf = [%--.*d]\n", 5, 42));
	printf("=========================\n");

//	pruebas i integer

	printf ("\n\n\033[33;01m	Pruebas \033[32;01mi \033[00m\n");

	printf("=========================\n");
	printf("		(1) Prueba numeros (i) [i]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%i] et [%i]\n", 42, -42));
	printf("valeur de retour = [%d]\n", printf("   printf = [%i] et [%i]\n", 42, -42));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(2) Prueba numeros (i) [10i]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%10i] et [%10i]\n",42, -42));
	printf("valeur de retour = [%d]\n", printf("   printf = [%10i] et [%10i]\n",42, -42));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(3) Prueba numeros (i) [10.10i]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%10.10i] et [%10.10i]\n",42, -42));
	printf("valeur de retour = [%d]\n", printf("   printf = [%10.10i] et [%10.10i]\n",42, -42));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(4) Prueba numeros (i) [-10i] y [-10.10i]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-10i] et [%-10.10i]\n",1, 35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-10i] et [%-10.10i]\n",1, 35));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(5) Prueba numeros (i) [010i] [010.4i]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%05i] et [%010.5i]\n", -12, 35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%05i] et [%010.5i]\n", -12, 35));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(6) Prueba numeros (i) [010.4i]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%010.4i]\n", 0));
	printf("valeur de retour = [%d]\n", printf("   printf = [%010.4i]\n", 0));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(7) Prueba numeros [.i] {42}{0}\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%.i] et [%.i]\n", 42, 0));
	printf("valeur de retour = [%d]\n", printf("   printf = [%.i] et [%.i]\n", 42, 0));
	printf("=========================\n");

//	pruebas u integer

	printf ("\n\n\033[33;01m	Pruebas \033[32;01mu \033[00m\n");

	printf("=========================\n");
	printf("		(1) Prueba numeros (u) [u]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%u] et [%u]\n", (unsigned int)3147483647, -42));
	printf("valeur de retour = [%d]\n", printf("   printf = [%u] et [%u]\n", (unsigned int)3147483647, -42));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(2) Prueba numeros (u) [10u]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%10u] et [%10u]\n",42, -42));
	printf("valeur de retour = [%d]\n", printf("   printf = [%10u] et [%10u]\n",42, -42));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(3) Prueba numeros (u) [10.10u]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%10.10u] et [%10.10u]\n",42, -42));
	printf("valeur de retour = [%d]\n", printf("   printf = [%10.10u] et [%10.10u]\n",42, -42));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(4) Prueba numeros (u) [-10u] y [-10.10u]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-10u] et [%-10.10u]\n",1, 35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-10u] et [%-10.10u]\n",1, 35));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(5) Prueba numeros (u) [010u] [010.4u]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%05u] et [%010.5u]\n", -12, 35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%05u] et [%010.5u]\n", -12, 35));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(6) Prueba numeros (u) [010.4u]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%010.4u]\n", 0));
	printf("valeur de retour = [%d]\n", printf("   printf = [%010.4u]\n", 0));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(7) Prueba numeros [.u] {42}{0}\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%.u] et [%.u]\n", 42, 0));
	printf("valeur de retour = [%d]\n", printf("   printf = [%.u] et [%.u]\n", 42, 0));
	printf("=========================\n");

//	pruebas X 

	printf ("\n\n\033[33;01m	Pruebas \033[32;01m(x & X) \033[00m\n");

	printf("=========================\n");
	printf("		(1) Prueba numeros (x & X) [x] [X]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%x] et [%X]\n", (unsigned int)3147483647, -35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%x] et [%X]\n", (unsigned int)3147483647, -35));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(2) Prueba numeros (x & X) [10x][10X]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%10x] et [%10X]\n",35, -35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%10x] et [%10X]\n",35, -35));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(3) Prueba numeros (x & X) [10.10x] [10.10X]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%10.10x] et [%10.10X]\n",35, -35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%10.10x] et [%10.10X]\n",35, -35));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(4) Prueba numeros (x & X) [-10x] y [-10.10X]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-10x] et [%-10.10X]\n",1, 35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-10x] et [%-10.10X]\n",1, 35));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(5) Prueba numeros (x & X) [010x] [010.5X]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%05x] et [%010.5X]\n", -12, 35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%05x] et [%010.5X]\n", -12, 35));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(6) Prueba numeros (x & X) [010.4x]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%010.4x]\n", 0));
	printf("valeur de retour = [%d]\n", printf("   printf = [%010.4x]\n", 0));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(7) Prueba numeros (x & X) {42}{0}\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%.x] et [%.X]\n", 42, 0));
	printf("valeur de retour = [%d]\n", printf("   printf = [%.x] et [%.X]\n", 42, 0));
	printf("=========================\n");

	printf ("\n\n\033[33;01m	Pruebas \033[32;01mPorcentaje \033[00m\n");

	printf("=========================\n");
	printf("		(1) Prueba numeros (35)\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%35%]\n"));
	printf("valeur de retour = [%d]\n", printf("   printf = [%35%]\n"));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(2) Prueba numeros (05)\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%05%]\n"));
	printf("valeur de retour = [%d]\n", printf("   printf = [%05%]\n"));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(3) Prueba numeros (05.3)\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%05.3%]\n"));
	printf("valeur de retour = [%d]\n", printf("   printf = [%05.3%]\n"));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(4) Prueba numeros (-5.3)\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-5.3%]\n"));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-5.3%]\n"));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(5) Prueba numeros (-*.38) {35}\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-*.38%]\n", 35));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-*.38%]\n", 35));
	printf("=========================\n");

	printf ("\n\n\033[33;01m	Pruebas \033[32;01mPointer \033[00m\n");
	char a = 'a';

	printf("=========================\n");
	printf("		(1) Prueba numeros (p)\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%p]\n", &a ));
	printf("valeur de retour = [%d]\n", printf("   printf = [%p]\n", &a));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(2) Prueba numeros (15p) \n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%15p]\n", &a));
	printf("valeur de retour = [%d]\n", printf("   printf = [%15p]\n", &a));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(3) Prueba numeros (.p) \n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%.p]\n", &a));
	printf("valeur de retour = [%d]\n", printf("   printf = [%.p]\n", &a));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(4) Prueba numeros (-p) \n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-p]\n", &a));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-p]\n", &a));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(5) Prueba numeros (-20p) {NULL} \n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-20p]\n", NULL));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-20p]\n", NULL));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(6) Prueba numeros (-20p) {NULL} \n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-20p]\n", NULL));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-20p]\n", NULL));
	printf("=========================\n");

	printf("=========================\n");
	printf("		(7) Prueba numeros (-20.p) \n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%-15p]\n", &a));
	printf("valeur de retour = [%d]\n", printf("   printf = [%-15p]\n", &a));
	printf("=========================\n");

	printf ("\n\n\033[33;01m	Pruebas \033[32;01mNULL \033[00m\n");

	printf("=========================\n");
	printf("		(1) Prueba char [c]\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%ctest]\n", 0));
	printf("valeur de retour = [%d]\n", printf("   printf = [%ctest]\n", 0));
	printf("=========================\n");


	printf("=========================\n");
	printf("		     Prueba string [10.4s] {NULL}\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%10.4s]\n", NULL));
	printf("valeur de retour = [%d]\n", printf("   printf = [%10.4s]\n", NULL));
	printf("=========================\n");

	printf("=========================\n");
	printf("		     Prueba string [d] {NULL} indefinido\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%d]\n", NULL));
//	printf("valeur de retour = [%d]\n", printf("   printf = [%d]\n", NULL));
	printf("=========================\n");


//	printf("   printf = [%000*.*d]\n\n", 10, 5, 42);
//	ft_printf("ft_printf = [%000*.*d]\n", 10, 5, 42);
/*

	printf("=========================\n");
	printf("		(5) Prueba numeros (-*.38) {35}\n");
	printf("valeur de retour = [%d]\n", ft_printf("ft_printf = [%10]\n"));
	printf("valeur de retour = [%d]\n", printf("   printf = [%10]\n"));
	printf("=========================\n");


	printf ("\033[37;01m====================================\033[00m\n");
	printf ("\033[34;01m		Bye\n\033[00m");
*/
	return (0);
}

/*
**										(ojo cuando nb = -)
**										(no sirve sin type)

**	flag 0 sirve con d i u x X
		| -> 0 "" sirve con d i u x X 
		| -> 0 0  sirve con d i u x X   -> 0 0 0 0 0 0 0 0 
		| -> 0 -  no
		| -> 0 *  sirve con d i u x X 
		| -> 0 .  no

**	flag - sirve con c s d i p u x X 
		| -> - "" sirve con todo -> - - - - - - ex %-5p
		| -> - -  sirve con todo -> - - - - - - ex %--40d 
		| -> - 0  (sirve con todo)
		| -> - *  (sirve con todo)
		| -> - .  sirve con s d i u x X  (sirve pero no hace nada con d)

**	flag . sirve con s x,X(pone 0 al principio)
		| -> . "" sirve con s d i u x X  
		| -> . .  no sirve 
		| -> . -  no sirve 
		| -> . 0  no se puede 
		| -> . *  s d i u x X 

**	flag * sirve con c s d i p u x X
		| -> * *  no sirve
		| -> * .  s d i u x X
		| -> * -  no sirve
		| -> * 0  no sirve


*/
