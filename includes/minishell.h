/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 00:00:25 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/29 19:16:09 by moerradi         ###   ########.fr       */
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
# include "../libft/libft.h"

int		ft_strslen(char **strs);
void	print_cwd(bool isred);
int		get_cmd_line(char **line);
int		echo(char **args);
int		cd(char **args);
int		unset(char **args);
int		export(char **args);
int		pwd(char **args);
int		env(char **args);


#endif