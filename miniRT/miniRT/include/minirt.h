/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:10:26 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/04 23:01:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "define.h"
# include "extern.h"
# include "struct.h"
# include "typedef.h"

int			exit_hook(t_data *data);
int			key_hook(int keycode, t_data *data);

void		print_error(char *msg, void *data);
void		print_custom_error(char *msg, void *data);
void		print_read_error(char *msg, char *loc, void *data, char **tokens);

t_bool		check_element_count(char **tokens);
t_bool		check_element_csv(char *csv, int type);
t_bool		check_element_value(char *elem, int type);
t_bool		check_file_ext(char	*file);

size_t		count_char(char *line, char c);
t_bool		is_int(char *elem);
t_bool		is_float(char *elem);

t_data		*init_data(void);

char		**parse_line(t_data *data, char *line);

void		read_file(t_data *data, char *file);

size_t		count_tokens(char **tokens);

t_canvas	set_canvas(int height);
void		set_data(char **tokens, t_data *data);

void		render(t_data *data);

void		free_struct(t_data *data);
void		free_tokens(char **tokens);

double		rt_atof(const char *str, int *error);
int			rt_atoi(const char *str, int *error);
void		rt_close(int fd, t_data *data);
int			rt_open(char *file, int flag, t_data *data);
void		*rt_malloc(size_t size, t_data *data);

long long	toll(const char *str, long long sign, size_t idx, int *error);
long long	tollp(const char *str, size_t idx, int *precision, int *error);

char		*rt_mlx_get_data_addr(t_data *data);
void		*rt_mlx_init(t_data *data);
void		*rt_mlx_new_image(t_data *data, int width, int height);
void		*rt_mlx_new_window(t_data *data, int sx, int sy, char *title);
void		rt_mlx_pixel_put(t_img *img, int x, int y, t_color3 color);

#endif
