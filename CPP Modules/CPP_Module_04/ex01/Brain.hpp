/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:34:27 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/16 19:41:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

class	Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain(void);
		~Brain(void);
		Brain(Brain const& target);
		Brain&	operator=(Brain const& target);
};

#endif	/* __BRAIN_HPP__ */
