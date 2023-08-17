/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:34:27 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 20:41:41 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__
# include <string>

class	Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain(void);
		~Brain(void);
		Brain(Brain const& target);
		Brain&	operator=(Brain const& target);

		std::string	getIdea(std::size_t idx);
		void		setIdea(std::size_t idx, std::string const& idea);
};

#endif	/* __BRAIN_HPP__ */
