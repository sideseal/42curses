/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:59:26 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/25 19:50:49 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "init.h"
# include "mlx.h"
# include "stdlib.h"

int	key_hook(int keycode, t_mlx *data);
int	exit_hook(void);

#endif
