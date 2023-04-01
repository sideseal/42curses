#include <stdio.h>
#include <ctype.h>

int	convert_char(char c)
{
	if (isdigit(c))
	{
		if (c == '1' || c == '0')
			return (-1);
		return (c - '0');
	}
	else
	{
		if (c == 'T' || c == 'J' || c == 'D' || c == 'K')
			return (10);
		if (c == 'A')
			return (1);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	char	*string;
	int		sum;
	int		ret;
	int		ace;
	int		i;

	if (argc != 2)
		return (1);
	string = argv[1];
	sum = 0;
	ace = 0;
	i = -1;
	while (string[++i] != '\0')
	{
		ret = convert_char(string[i]);
		if (ret < 0)
			return (1);
		if (ret == 1)
		{
			ace++;
			continue ;
		}
		sum += ret;
	}
	i = 0;
	while (ace--)
	{
		if (!i++ && sum < 21)
		{
			ret = 11;
			if (sum + ret > 21)
				ret = 1;
		}
		else
			ret = 1;
		sum += ret;
	}
	if (sum == 21)
		printf("Blackjack!\n");
	else
		printf("%d\n", sum);
	return (0);
}
