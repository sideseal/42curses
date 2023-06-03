/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:10:26 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/03 23:23:29 by gychoi           ###   ########.fr       */
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

void		print_error(char *string, void *data);
void		print_custom_error(char *string, void *data);
void		print_read_error(char *string, void *data, char **tokens);

t_bool		check_elem_fmt(char **tokens);
t_bool		check_file_ext(char	*file);

t_data		*init_data(void);

char		**parse_line(t_data *data, char *line);

size_t		count_tokens(char **tokens);
void		read_file(t_data *data, char *file);

t_canvas	set_canvas(int height);
void		set_data(char **tokens, t_data *data);

void		render(t_data *data);

void		free_struct(t_data *data);
void		free_tokens(char **tokens);

void		rt_close(int fd, t_data *data);
int			rt_open(char *file, int flag, t_data *data);
void		*rt_malloc(size_t size, t_data *data);

char		*rt_mlx_get_data_addr(t_data *data);
void		*rt_mlx_init(t_data *data);
void		*rt_mlx_new_image(t_data *data, int width, int height);
void		*rt_mlx_new_window(t_data *data, int size_x, int size_y, char *title);
void		rt_mlx_pixel_put(t_img *img, int x, int y, t_color3 color);

#endif
