/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:05:38 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/04 20:02:28 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_leaks(void)
{
	// 지우는거 잊지 말기
	system("leaks --list -- miniRT");
}

void	print_error(char *msg, void *data)
{
	printf("Error\n");
	perror(msg);
	free_struct(data);
	atexit(check_leaks);
	exit(1);
}

void	print_custom_error(char *msg, void *data)
{
	printf("Error\n");
	printf("%s\n", msg);
	free_struct(data);
	atexit(check_leaks);
	exit(1);
}

void	print_read_error(char *msg, char *loc, void *data, char **tokens)
{
	printf("Error\n");
	printf("malformed file : ");
	if (loc != NULL)
		printf("%s\n", loc);
	printf("%s\n", msg);
	free_tokens(tokens);
	free_struct(data);
	atexit(check_leaks);
	exit(1);
}
