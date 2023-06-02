/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:10:26 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/02 21:10:50 by gychoi           ###   ########.fr       */
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

t_bool		check_file_ext(char	*file);

t_data		*init_data(void);

void		read_file(t_data *data, char *file);

t_canvas	set_canvas(int height);
t_scene		set_scene(void);

void		render(t_data *data);

void		free_struct(t_data *data);

void		rt_close(int fd, t_data *data);
int			rt_open(char *file, int flag, t_data *data);
void		*rt_malloc(size_t size, t_data *data);

char		*rt_mlx_get_data_addr(t_data *data);
void		*rt_mlx_init(t_data *data);
void		*rt_mlx_new_image(t_data *data, int width, int height);
void		*rt_mlx_new_window(t_data *data, int size_x, int size_y, char *title);
void		rt_mlx_pixel_put(t_img *img, int x, int y, t_color3 color);

#endif
