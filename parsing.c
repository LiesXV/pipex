/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:56:14 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/20 15:51:52 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **path, char *cmd)
{
	char	*test;
	int		i;
	int		result;
	
	result = -1;
	i = 0;
	test = NULL;
	while (path[i] && result == -1)
	{
		test = ft_strjoin(path[i], "/");
		if (!test)
			return (free(test), NULL);
		test = ft_strjoin(test, cmd);
		if (!test)
			return (free(test), NULL);
		if (access(test, F_OK | X_OK) == 0)
			result = 1;
		if (result == -1)
			free(test);
		i++;
	} 
	return (test);
}

int	fill_data(char **argv, t_data *args)
{
	args->infile = ft_strdup(argv[1]);
	if (!args->infile)
		return (-1);
	args->cmd1 = ft_split(argv[2], ' ');
	if (!args->cmd1)
		return (-1);
	args->path1 = get_path(args->env, args->cmd1[0]);
	if (!args->path1)
		return (-1);
	args->outfile = ft_strdup(argv[4]);
	if (!args->outfile)
		return (-1);
	args->cmd2 = ft_split(argv[3], ' ');
	if (!args->cmd2)
		return (-1);
	args->path2 = get_path(args->env, args->cmd2[0]);
	if (!args->path2)
		return (-1);
	return (0);
}