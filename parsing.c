/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:56:14 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/21 13:40:41 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **path, char *cmd)
{
	char	*test;
	char	*tmp;
	int		i;
	int		result;
	
	result = -1;
	i = 0;
	while (path[i] && result == -1)
	{
		if (i > 0)
			free(test);
		tmp = ft_strdup(path[i]);
		if(!tmp)
			return (NULL);
		tmp = ft_strfjoin(tmp, "/");
		if (!tmp)
			return (NULL);
		test = ft_strfjoin(tmp, cmd);
		if (!test)
			return (NULL); 
		if (access(test, F_OK | X_OK) == -1)
			result = -1;
		else
			return (test);
		i++;
	}
	return (free(test), NULL);
}

int	fill_data(char **argv, t_data *args)
{
	args->infile = ft_strdup(argv[1]);
	if (!args->infile)
		return (-1);
	args->cmd1 = ft_split(argv[2], ' ');
	if (!args->cmd1)
		return (-1);
	args->cmd2 = ft_split(argv[3], ' ');
	if (!args->cmd2)
		return (-1);
	args->outfile = ft_strdup(argv[4]);
	if (!args->outfile)
		return (-1);
	args->path1 = get_path(args->env, args->cmd1[0]);
	if (!args->path1)
		return (-1);
	args->path2 = get_path(args->env, args->cmd2[0]);
	if (!args->path2)
		return (-1);
	return (0);
}