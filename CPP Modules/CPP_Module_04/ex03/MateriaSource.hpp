/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 23:17:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/08/17 23:37:10 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria*	list[4];

	public:
		MateriaSource(void);
		virtual ~MateriaSource(void);
		MateriaSource(MateriaSource const& target);
		MateriaSource&	operator=(MateriaSource const& target);

		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const& type);
};

#endif	/* __MATERIASOURCE_HPP__ */
