/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 01:05:04 by moerradi          #+#    #+#             */
/*   Updated: 2021/01/06 00:16:00 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// if the argument number is greater than 1 it outputs "cd: too many arguments"
// if cd is run with no args it changes dir to the $home path
// it returns 0 if the dir changed correctly and 1 if there is an error
extern int errno;

int		cd(char **args)
{
	int arg_count;
	int tmperr;
	arg_count = ft_strslen(args);
	//if (!arg_count)
		//change wd to $HOME
	if (arg_count == 1)
	{
		//dont forget errno
		if ((chdir(args[0]) == -1))
		{
			tmperr = errno;
			ft_printf("cd: %s: %s\n", args[0], strerror(tmperr));
		}
	}
	if (arg_count > 1)
	{
		ft_printf("cd: too many arguments\n");
		return (1);
	}
}
