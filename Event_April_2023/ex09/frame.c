#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int	get_max_strlen(char *string, char *delim)
{
	int		len;
	int		max;
	int		i;
	char	*copystr;
	char	*save_copy;
	char	*token;

	copystr = strdup(string);
	save_copy = copystr;
	len = 0;
	max = 0;
	token = strtok(copystr, delim);
	while (token != NULL)
	{
		len = strlen(token);
		if (len > max)
			max = len;
		token = strtok(NULL, delim);
	}
	free(save_copy);
	return (max);
}

int	main(int argc, char **argv)
{
	int		max;
	int		i;
	char	*token;
	char	delim[] = " \n\t\v\f\r";

	if (argc == 1)
		return (1);
	max = get_max_strlen(argv[1], delim);
	i = -1;
	while (++i < max + 4)
		printf("*");
	printf("\n");
	token = strtok(argv[1], delim);
	while (token != NULL)
	{
		printf("* ");
		printf("%-*s", max, token);
		printf(" *\n");
		token = strtok(NULL, delim);
	}
	i = -1;
	while (++i < max + 4)
		printf("*");
	printf("\n");
	return (0);
}
