/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_3rd_arg_explained.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerradi <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:57:33 by moerradi          #+#    #+#             */
/*   Updated: 2020/12/28 23:58:25 by moerradi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the last argument of main '**env' magically passes all the env variables from
//the system shell to our program as displayed below it is terminated with a NULL to indicate it's end
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	int i = 0;
	while (env[i])
		printf("%s\n", env[i++]);
	return (0);
}