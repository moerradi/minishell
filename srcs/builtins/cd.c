/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 01:05:04 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/31 00:03:12 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// the cd builtin has two modes one arg or two args with two different behaviours
// and if the argument number is greater than 2 it outputs "cd: too many arguments"
// if cd is run with no args it changes dir to the $home path
// it returns 0 if the dir changed correctly and 1 if there is an error

int		handle_errno(char **args)
{
	
}

int		cd(char **args)
{
	int arg_count;

	arg_count = ft_strslen(args);
	//if (!arg_count)
		//change wd to $HOME
	if (arg_count == 1)
	{
		//dont forget errno
	}
	if (arg_count == 2)
	{
		ft_putendl_fd("cd: comming soon HH", 1);
		return (1);
	}
		//replicate the 2 args behaviour
	if (arg_count > 2)
	{
		ft_putendl_fd("cd: too many arguments", 1);
		return (1);
	}
}
