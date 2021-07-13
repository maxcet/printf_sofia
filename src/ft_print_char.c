#include "ft_printf.h"

void	ft_print_char(va_list args, int *bytes, int *index)
{
	int	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	(*bytes)++;
	(*index)++;
}

void	ft_printf_string(va_list args, int *bytes, int *index)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)\0";
	write(1, str, ft_strlen(str));
	*bytes = (*bytes) + ft_strlen(str);
	(*index)++;
}

void	ft_print_pointer(va_list args, int *bytes, int *index)
{
	unsigned long	p;

	p = (unsigned long)va_arg(args, void *);
	write(1, "0x", 2);
	(*bytes) = (*bytes) + 2;
	ft_putnbr_ptr_x(p, bytes);
	(*index)++;
}
