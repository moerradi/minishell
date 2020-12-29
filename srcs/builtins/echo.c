/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <moerradi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 00:13:57 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/29 14:33:17 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// as simple is it seems echo function is pretty hard when it comes to replicate
// the same exact behaviour it has in bash, the difernce betwen single and double
// quotes and the way it handles env variables printing is so wierd be careful to
// the way it comboes with the env command it has a strange behaviour as explained
// in the README.md
int		echo(char **args);
