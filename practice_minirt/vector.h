/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:14:45 by gychoi            #+#    #+#             */
/*   Updated: 2023/05/04 16:29:54 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_point3	color3(double r, double g, double b);
void		vset(t_vec3 *vec, double x, double y, double z);
double		vlen(t_vec3 vec);
t_vec3		vadd_v(t_vec3 ret, t_vec3 vec);
t_vec3		vadd_d(t_vec3 ret, double x, double y, double z);
t_vec3		vsub_v(t_vec3 ret, t_vec3 vec);
t_vec3		vsub_d(t_vec3 ret, double x, double y, double z);
t_vec3		vmul_v(t_vec3 ret, t_vec3 vec);
t_vec3		vmul_d(t_vec3 ret, double t);
t_vec3		vdiv_d(t_vec3 ret, double t);
double		vdot(t_vec3 v1, t_vec3 v2);
t_vec3		vcross(t_vec3 v1, t_vec3 v2);
t_vec3		vunit(t_vec3 ret);
t_vec3		vmin(t_vec3 ret, t_vec3 vec);

#endif
