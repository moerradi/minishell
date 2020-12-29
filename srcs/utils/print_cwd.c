/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:19:48 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/29 19:03:32 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// function that print the curent working directory
// wil need later updates I guess but it is humble and good now
void	print_arrow(bool isred)
{
	if (isred)
		ft_putstr_fd("\033[0;31m➜\033[0m  ", 1);
	else
		ft_putstr_fd("\033[0;32m➜\033[0m  ", 1);

}

void	print_cwd(bool isred)
{
	char	*cwd;
	char	buf[4097];

	cwd = getcwd(buf, 4096);
	print_arrow(isred);
	ft_putstr_fd("\033[1;36m", 1);
	ft_putstr_fd(ft_strrchr(cwd,'/') + 1, 1);
	ft_putstr_fd("\033[0m[MSBETA] ", 1);
}