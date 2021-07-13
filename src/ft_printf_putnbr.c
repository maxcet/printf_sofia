#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *bytes)
{
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
		(*bytes)++;
	}
	else
	{
		ft_putnbr(n / 10, bytes);
		ft_putnbr(n % 10, bytes);
	}
}

void	ft_putnbr_x(unsigned  int n, int *bytes)
{
	if (n > 15)
		ft_putnbr_x ((n / 16), bytes);
	if ((n % 16) <= 9 && (n % 16) >= 0)
		*bytes = ft_putchar((n % 16 + 48), bytes);
	if ((n % 16) == 10)
		*bytes = ft_putchar('a', bytes);
	if ((n % 16) == 11)
		*bytes = ft_putchar('b', bytes);
	if ((n % 16) == 12)
		*bytes = ft_putchar('c', bytes);
	if ((n % 16) == 13)
		*bytes = ft_putchar('d', bytes);
	if ((n % 16) == 14)
		*bytes = ft_putchar('e', bytes);
	if ((n % 16) == 15)
		*bytes = ft_putchar('f', bytes);
}

void	ft_putnbr_xx(unsigned  int n, int *bytes)
{
	if (n > 15)
		ft_putnbr_xx ((n / 16), bytes);
	if ((n % 16) <= 9 && (n % 16) >= 0)
		*bytes = ft_putchar(((n % 16) + 48), bytes);
	if ((n % 16) == 10)
		*bytes = ft_putchar('A', bytes);
	if ((n % 16) == 11)
		*bytes = ft_putchar('B', bytes);
	if ((n % 16) == 12)
		*bytes = ft_putchar('C', bytes);
	if ((n % 16) == 13)
		*bytes = ft_putchar('D', bytes);
	if ((n % 16) == 14)
		*bytes = ft_putchar('E', bytes);
	if ((n % 16) == 15)
		*bytes = ft_putchar('F', bytes);
}

void	ft_putnbr(int n, int *bytes)
{
	char	minus;

	minus = '-';
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*bytes) += 11;
	}
	else if (n >= 0 && n <= 9)
		*bytes = ft_putchar((n + 48), bytes);
	else if (n > 9)
	{
		ft_putnbr(n / 10, bytes);
		ft_putnbr(n % 10, bytes);
	}
	else
	{
		n = -n;
		write(1, &minus, 1);
		ft_putnbr(n, bytes);
		(*bytes)++;
	}
}

void	ft_putnbr_ptr_x(unsigned  long n, int *bytes)
{
	if (n > 15)
		ft_putnbr_ptr_x ((n / 16), bytes);
	if ((n % 16) <= 9 && (n % 16) >= 0)
		*bytes = ft_putchar((n % 16 + 48), bytes);
	if ((n % 16) == 10)
		*bytes = ft_putchar('a', bytes);
	if ((n % 16) == 11)
		*bytes = ft_putchar('b', bytes);
	if ((n % 16) == 12)
		*bytes = ft_putchar('c', bytes);
	if ((n % 16) == 13)
		*bytes = ft_putchar('d', bytes);
	if ((n % 16) == 14)
		*bytes = ft_putchar('e', bytes);
	if ((n % 16) == 15)
		*bytes = ft_putchar('f', bytes);
}