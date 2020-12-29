/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:24:02 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/29 16:48:09 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
// main shell loop
// remembre these are the allowed functions : malloc, free, write, open, read, close, fork, wait,
//waitpid, wait3, wait4, signal, kill, exit, getcwd,
//chdir, stat, lstat, fstat, execve, dup, dup2, pipe,
//opendir, readdir, closedir, strerror, errno

void	handle_sigs(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		print_cwd();
	}
}

int main(int argc, char **argv, char **env)
{
	char	*line;
	char	**pipes;
	char	**commands;

	(void)argc;
	(void)argv;
	while (true)
	{
		signal(SIGINT, handle_sigs);
		print_cwd();
		if (get_cmd_line(0, &line) == 0)
			if (ft_strlen(line) ==  0)
				break;
		pipes = ft_split();
	}
	//free_env();
	return (0);
}