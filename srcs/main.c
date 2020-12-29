/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:24:02 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/29 01:29:27 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
// main shell loop
// remembre these are the allowed functions : malloc, free, write, open, read, close, fork, wait,
//waitpid, wait3, wait4, signal, kill, exit, getcwd,
//chdir, stat, lstat, fstat, execve, dup, dup2, pipe,
//opendir, readdir, closedir, strerror, errno

void	handle_sigint(int sig)
{
	//if (sig = sigin)
		printf("hello %i\n", sig);
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	char	*line;

	while (true)
	{
		// print_cwd();
		//signal(SIG, handle_sigint);
		get_next_line(0, &line);
	}
	//free_env();
	return (0);
}