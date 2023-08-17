/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:36:58 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 22:38:10 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CURE_HPP__
# define __CURE_HPP__
# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Cure : public AMateria
{
	public:
		Cure(void);
		virtual ~Cure(void);
		Cure(Cure const& target);
		Cure&	operator=(Cure const& target);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter &target);
};

#endif	/* __CURE_HPP__ */
