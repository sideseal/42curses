/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:03:00 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/24 18:55:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "mlx.h"
# include "pracrt.h"
# include "struct.h"

t_mlx	init_mlx(void);
t_img	init_img(t_mlx mlx);

#endif
