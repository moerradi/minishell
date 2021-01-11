/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 00:00:25 by moerradi          #+#    #+#             */
/*   Updated: 2021/01/06 01:07:11 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include "../ft_printf/includes/libftprintf.h"

// general stctur that will contain all we need
typedef struct		s_msh
{
	char			**cmds;
	char			**pipes;
	//char			**
}					t_msh;

char				**parseline(char const *s);
int					ft_strslen(char **strs);
void				print_cwd(bool isred);
int					get_cmd_line(char **line);
int					echo(char **args);
int					cd(char **args);
int					unset(char **args);
int					export(char **args);
int					pwd(char **args);
int					env(char **args);
int					bash_exit(char **args);

#endif