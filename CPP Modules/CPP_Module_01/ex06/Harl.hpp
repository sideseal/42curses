/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:12:49 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/28 01:38:17 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>
#include <string>

enum LogLevel
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	LEVEL_SIZE,
};

class	Harl
{
	public:
		void	complain(std::string level);

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif
