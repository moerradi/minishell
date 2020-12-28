/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:24:02 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/29 00:00:04 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// main shell loop
// remembre these are the allowed functions : malloc, free, write, open, read, close, fork, wait,
//waitpid, wait3, wait4, signal, kill, exit, getcwd,
//chdir, stat, lstat, fstat, execve, dup, dup2, pipe,
//opendir, readdir, closedir, strerror, errno

// the last argument of main '**env' magically passes all the env variables from
//the system shell to our program as displayed below it is terminated with a NULL to indicate it's end
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
		
	while (true)
	{
		//the shell loop
		// if exit signal CTRL-D : break
	}
	free_env();
	return (0);
}