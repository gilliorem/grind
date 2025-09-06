#include "../include/task.h"

static int	get_size_and_convert(int n, unsigned int *num)
{
	int	size;
	int	temp;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	temp = n;
	if (n < 0)
		*num = (unsigned int)(-(long)n);
	else
		*num = (unsigned int)n;
	while (temp != 0)
	{
		size++;
		temp /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	n_dup;
	char			*result;
	int				size;
	int				i;

	size = get_size_and_convert(n, &n_dup);
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size] = '\0';
	i = size - 1;
	if (n_dup == 0)
		result[i--] = '0';
	while (n_dup > 0)
	{
		result[i--] = (n_dup % 10) + '0';
		n_dup /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
/*
int	main()
{
	char *result = ft_itoa(-23456789);
	printf("main result: %s\n", result);
}
*/
