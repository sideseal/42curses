/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:43:02 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/11 21:03:00 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>
# include <unistd.h>

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_point3	color3(double r, double g, double b);
void		vset(t_vec3 *vec, double x, double y, double z);
double		vlen(t_vec3 vec);
double		vlen_pow(t_vec3 vec);
t_vec3		vadd(t_vec3 ret, t_vec3 vec);
t_vec3		vadds(t_vec3 ret, double x, double y, double z);
t_vec3		vsub(t_vec3 ret, t_vec3 vec);
t_vec3		vsubs(t_vec3 ret, double x, double y, double z);
t_vec3		vmult(t_vec3 ret, t_vec3 vec);
t_vec3		vmults(t_vec3 ret, double t);
t_vec3		vdivs(t_vec3 ret, double t);
double		vdot(t_vec3 v1, t_vec3 v2);
t_vec3		vcross(t_vec3 v1, t_vec3 v2);
t_vec3		vunit(t_vec3 ret);
t_vec3		vmin(t_vec3 ret, t_vec3 vec);
t_vec3		vmax(t_vec3 ret, t_vec3 vec);

#endif
