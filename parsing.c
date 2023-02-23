/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:56:14 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/23 15:01:53 by ibenhaim         ###   ########.fr       */
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

t_list	*fill_list(int argc, char **argv, t_data *args)
{
	t_list	*stack_a;
	t_list	*cell;
	char	**split;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		split = ft_split(argv[i], ' ');
		if(!split)
			return (NULL);
		if (i == 0)
		{
			stack_a = ft_lstnew(split, args);
			if (!stack_a)
				return (ft_lstclear(&stack_a), NULL);
		}
		else
		{
			cell = ft_lstnew(split, args);
			if (!cell)
				return (ft_lstclear(&stack_a), NULL);
			ft_lstadd_back(&stack_a, cell);
		}
		i++;
	}
	return (stack_a);
}

int	fill_data(int argc, char **argv, t_data *args)
{
	if (ft_strncmp(argv[0], "here_doc") == 0)
	{
		args->hdoc = 1;
		args->mode = O_APPEND;
	}
	else
	{
		args->hdoc = 0;
		args->mode = O_TRUNC;
	}
	args->infile = ft_strdup(argv[0 + args->hdoc]);
	if (!args->infile)
		return (-1);
	args->outfile = ft_strdup(argv[argc - 1]);
	if (!args->outfile)
		return (-1);
	args->lst = fill_list(argc - 1 - args->hdoc, argv + 1 + args->hdoc, args);
	if (!args->lst)
		return (-1);
	ft_lstprint(args->lst);
	return (0);
}