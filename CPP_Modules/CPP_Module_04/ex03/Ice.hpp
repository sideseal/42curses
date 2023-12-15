/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:15:56 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 22:18:32 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ICE_HPP__
# define __ICE_HPP__
# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Ice : public AMateria
{
	public:
		Ice(void);
		virtual ~Ice(void);
		Ice(Ice const& target);
		Ice&	operator=(Ice const& target);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif	/* __ICE_HPP__ */
