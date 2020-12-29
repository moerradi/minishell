/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 01:05:04 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/29 19:46:31 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// the cd builtin has two modes one arg or two args with two different behaviours
// and if the argument number is greater than 2 it outputs "cd: too many arguments"
// if cd is run with no args it changes dir to the $home path
// it returns 0 if the dir changed correctly and 1 if there is an error
int		cd(char **args);
