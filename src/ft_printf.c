#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes;
	int		index;

	index = 0;
	va_start(args, format);
	bytes = 0;
	while (format[index] != '\0')
	{
		while (format[index] != '%' && format[index] != '\0')
		{
			write(1, &format[index++], 1);
			bytes++;
		}
		while (format[index] == '%')
		{
			if (ft_define_format(format[index + 1]) == 1)
				ft_print_arg(&bytes, &index, args, format);
			if (format[index] == '%')
				ft_kostil(&index, &bytes);
		}
	}
	va_end(args);
	return (bytes);
}

void	ft_kostil(int *index, int *bytes)
{	
	*index += 2;
	ft_printf_per(bytes);
}

int	ft_define_format(char c)
{
	int		i;
	char	*CONV;

	CONV = "cspdiuxX";
	i = 0;
	while (CONV[i] != '\0')
	{
		if (c == CONV[i])
			return (1);
		i++;
	}
	return (0);
}

int	*ft_print_arg(int *bytes, int *index, va_list args, const char *format)
{
	while (format[*index] == '%')
	{
		if (args == NULL)
			return (0);
		if (format[(*index) + 1] == 'd' || format[(*index) + 1] == 'i')
			ft_print_iteger_dec(args, bytes, index);
		else if (format[(*index) + 1] == 'c')
			ft_print_char(args, bytes, index);
		else if (format[(*index) + 1] == 's')
			ft_printf_string(args, bytes, index);
		else if (format[(*index) + 1] == 'u')
			ft_print_unsigned_dec(args, bytes, index);
		else if (format[(*index) + 1] == 'x')
			ft_print_hexadecimal(args, bytes, index);
		else if (format[(*index) + 1] == 'X')
			ft_print_hexadecimal_p(args, bytes, index);
		else if (format[(*index) + 1] == 'p')
			ft_print_pointer(args, bytes, index);
		(*index)++;
	}
	return (bytes);
}
