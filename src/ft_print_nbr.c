#include "ft_printf.h"

void	ft_print_unsigned_dec(va_list args, int *bytes, int *index)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	ft_putnbr_u(u, bytes);
	(*index)++;
}

void	ft_print_hexadecimal_p(va_list args, int *bytes, int *index)
{
	int	x;

	x = va_arg(args, unsigned int);
	ft_putnbr_xx(x, bytes);
	(*index)++;
}

void	ft_print_hexadecimal(va_list args, int *bytes, int *index)
{
	int	x;

	x = va_arg(args, unsigned int);
	ft_putnbr_x(x, bytes);
	(*index)++;
}

void	ft_print_iteger_dec(va_list args, int *bytes, int *index)
{
	int	d;

	d = va_arg(args, int);
	ft_putnbr(d, bytes);
	(*index)++;
}

void	ft_printf_per(int *bytes)
{
	write(1, "%", 1);
	(*bytes)++;
}
