/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 00:00:25 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/29 14:33:04 by moerradi         ###   ########.fr       */
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

void	print_cwd(void);
int		echo(char **args);
int		cd(char **args);
int		unset(char **args);
int		export(char **args);
int		pwd(char **args);
int		env(char **args);


#endif