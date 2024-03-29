/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:24:02 by moerradi          #+#    #+#             */
/*   Updated: 2021/01/06 02:49:56 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
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
		print_cwd(true);
	}
}

bool	check_builtins(char **args)
{
	if (!ft_strcmp("cd",args[0]))
		return (cd(args + 1));
	// if (!ft_strcmp("echo", args[0]))
	// 	return (echo(args + 1));
	// if (!ft_strcmp("env", args[0]))
	// 	return (env(args + 1));
	// if (!ft_strcmp("export", args[0]))
	// 	return (export(args + 1));
	// if (!ft_strcmp("pwd", args[0]))
	// 	return (export(args + 1));
	// if (!ft_strcmp("unset", args[0]))
	// 	return (unset(args + 1));
	if (!ft_strcmp("exit", args[0]))
		return (bash_exit(args + 1));
}

bool	send_command(char *command)
{
	char	**args;

	args = ft_split(command, ' ');
	check_builtins(args);
}

void	commands_router(char **commands)
{
	int i;

	i = 0;
	while (commands[i])
		send_command(commands[i++]);
}

int 	main(int argc, char **argv, char **env)
{
	char	*line;
	char	**commands;
	t_list	*envvs;

	(void)argc;
	(void)argv;
	if (!(envvs = ft_lstnew("?=0")))
		return (-1);
	while (true)
	{
		signal(SIGINT, handle_sigs);
		print_cwd(false);
		if (get_cmd_line(&line) == 0)
			if (ft_strlen(line) ==  0)
			{
				free(line);
				break;
			}
		// i will not handle pipes tenporarly to test builtins
		// i will handle only ';'
		//pipes = ft_split(line, '|');
		// todo : check if all pipes are valid and not ending with a ; or
		//a char with an undefined behaviour
		//check_valid_pipes(pipes);
		//using split temporarly to test builtins
		if ((commands = ft_split(line, ';')))
			commands_router(commands);
	}
	//free_env();
	return (0);
}