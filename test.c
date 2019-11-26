
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "printf.h"

int	ft_test(t_form *a)
{
	a->prec = 5;
	return (0);
}
int main()
{
	t_form a;
	char s[] = "sn.dh0t*";
	int i = 0;
	a.prec = 0;
	ft_test(&a);

/**	a.flag = 0;
	while (s[i])
	{
		if (s[i] == '-')
			a.flag |= FLAG_MIN;
		else if (s[i] == '0')
			a.flag |= FLAG_ZERO;
		else if (s[i] == '.')
			a.flag |= FLAG_DOT;
		else if (s[i] == '*')
			a.flag |= FLAG_STAR;
		i++;
	}
	if (FLAG_MIN & a.flag)
		printf("%d", 1);
	else
		printf("%d", 0);
	if (FLAG_ZERO & a.flag)
		printf("%d", 1);
	else
		printf("%d", 0);
	if (FLAG_DOT & a.flag)
		printf("%d", 1);
	else
		printf("%d", 0);
	if (FLAG_STAR & a.flag)
		printf("%d", 1);
	else
		printf("%d", 0);
*/
	printf("----->%010k");
	return (0);
}
