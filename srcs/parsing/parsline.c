/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:19:52 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/31 00:32:53 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

// this is just a temporary parsing function will enhance later
// parsline parses the line into commandsby splitting by ';' and cheking if the
// line doesn't contain mltiple ';' after each other
static size_t	count_cmds(char const *str)
{
	int		t;
	size_t	wc;

	t = 1;
	wc = 0;
	while (*str)
	{
		if (*str == ';')
			t = 1;
		else if (t == 1)
		{
			t = 0;
			wc++;
		}
		str++;
	}
	return (wc);
}

static char		**ft_garbage(char ***s, size_t idx)
{
	char	**splitout;
	size_t	i;

	i = 0;
	splitout = *s;
	while (i < idx)
	{
		free(splitout[i]);
		i++;
	}
	free(splitout);
	splitout = NULL;
	return (splitout);
}
// basic function that prints the parse error and does the necessary cleanup
char	**parse_err(char ***s, int i)
{
	ft_putendl_fd("msh: parse error near `;;'", 1);
	return (ft_garbage(s, i - 1));
}
// parseline function temporatly handles the ';' only will handle pipes
// and redirections later
char	**parseline(char const *s)
{
		char			**out;
	size_t			i; 
	unsigned int	start;
	size_t			len;

	i = 0;
	start = 0;
	if (s == NULL || !(out = malloc(sizeof(char*) * (count_cmds(s) + 1))))
		return (NULL);
	while (i < count_cmds(s))
	{
		if (s[start] && s[start++] == ';')
			if (s[start] && s[start] == ';')
				return parse_err(&out, i);
		len = 0;
		while (s[len + start] && s[len + start] != ';')
			len++;
		if (!(out[i++] = ft_substr(s, start, len)))
			return (ft_garbage(&out, i - 1));
		start += len;
	}
	out[i] = NULL;
	return (out);
}

int main()
{
	char **test;

	test = parseline("test");
	int i = 0;
	if (test)
		while (test[i])
			printf("%s\n", test[i++]);
}