/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:39:54 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/29 22:06:56 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int		bash_exit(char **args)
{
	int arg_count;

	arg_count = ft_strslen(args);
	if (!arg_count)
	{
		//pre_exit_cleanup(...);
		// this is supposed to be the exit code of the last command run according to
		// https://linuxize.com/post/bash-exit/
		// but I will put 0 temporatly untill we implement $? env variable
		exit(0);
	}
	else if (arg_count == 1)
	{
		//pre_exit_cleanup(...);
		exit(ft_atoi(args[0]));
	}
	else if (arg_count > 1)
		ft_putendl_fd("exit: too many arguments", 1);
}