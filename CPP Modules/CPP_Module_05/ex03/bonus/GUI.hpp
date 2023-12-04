/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:56:41 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/04 22:07:07 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __GUI_HPP__
#define __GUI_HPP__

#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>

#define OK (1)
#define ERR (0)

void	resetTerminal();
bool	configureTerminal();
void	eraseTerminal();
int		readInput();
int		readKey(char* buf, int k);

#endif /* __GUI_HPP__ */
