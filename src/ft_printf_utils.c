#include "ft_printf.h"

int	ft_putchar(char c, int *bytes)
{
	write (1, &c, 1);
	*bytes = *bytes + 1;
	return (*bytes);
}

int	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}
