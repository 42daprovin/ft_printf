
#include "libft/libft.h"
#include "printf.h"

int	ft_test(t_form *a)
{
	a->prec = 5;
	return (0);
}
int main()
{
//	printf("----->%12x\n", (unsigned int)78);
//	ft_printf("----->%12x\n", (unsigned int)78);

	void *p;
	unsigned long n;

	n = (unsigned long)p;
//	ft_printf("%x\n", n);
	printf("%lx\n", n);
	printf("%p\n", p);
	return (0);
}
