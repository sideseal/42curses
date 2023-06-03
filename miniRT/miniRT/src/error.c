/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:05:38 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/03 23:26:56 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_leaks(void)
{
	// 지우는거 잊지 말기
	system("leaks --list -- miniRT");
}

void	print_error(char *string, void *data)
{
	printf("Error\n");
	perror(string);
	free_struct(data);
	atexit(check_leaks);
	exit(1);
}

void	print_custom_error(char *string, void *data)
{
	printf("Error\n");
	printf("%s\n", string);
	free_struct(data);
	atexit(check_leaks);
	exit(1);
}

void	print_read_error(char *string, void *data, char **tokens)
{
	printf("Error\n");
	printf("malformed file : %s\n", string);
	free_tokens(tokens);
	free_struct(data);
	atexit(check_leaks);
	exit(1);
}
