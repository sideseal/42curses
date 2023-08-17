/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:00:08 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 22:11:13 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__
# include <string>

class	ICharacter;

class	AMateria
{
	protected:
		std::string	type;

	public:
		AMateria(void);
		virtual ~AMateria(void);
		AMateria(std::string const& type);
		AMateria(AMateria const& target);
		AMateria&	operator=(AMateria const& target);

		std::string const&	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);
};

#endif	/* __AMATERIA_HPP__ */
