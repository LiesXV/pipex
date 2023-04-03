/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:56:14 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/04/03 10:49:51 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_cmd(char *path, char *cmd)
{
	char	*tmp;
	char	*result;

	tmp = ft_strdup(path);
	if (!tmp)
		return (NULL);
	tmp = ft_strfjoin(tmp, "/");
	if (!tmp)
		return (NULL);
	result = ft_strfjoin(tmp, cmd);
	if (!result)
		return (NULL);
	return (result);
}

char	*get_path(char **path, char *cmd)
{
	char	*test;
	int		i;
	int		result;

	result = -1;
	i = -1;
	test = ft_strdup(cmd);
	if (access(cmd, F_OK | X_OK) == 0)
		return (test);
	while (path[++i] && result == -1)
	{
		free(test);
		test = join_cmd(path[i], cmd);
		if (!test)
			return (NULL);
		if (access(test, F_OK | X_OK) == -1)
			result = -1;
		else
			return (test);
	}
	return (free(test), NULL);
}

t_list	*fill_list(int argc, char **argv, t_data *args)
{
	t_list	*stack_a;
	t_list	*cell;
	int		i;

	i = 0;
	stack_a = ft_lstnew(argv[i], args);
	if (!stack_a)
		return (NULL);
	while (++i < argc - 1)
	{
		cell = ft_lstnew(argv[i], args);
		if (!cell)
			return (ft_lstclear(&stack_a), NULL);
		ft_lstadd_back(&stack_a, cell);
	}
	return (stack_a);
}

int	assign_mode(char **argv, t_data *args)
{
	if (ft_strncmp(argv[0], "here_doc", 8) == 0)
	{
		args->hdoc = 1;
		args->limiter = ft_strdup(argv[1]);
		if (!args->limiter)
			return (-1);
		args->limiter = ft_strfjoin(args->limiter, "\n");
		if (!args->limiter)
			return (-1);
		read_input(args);
		args->mode = O_APPEND;
	}
	else
	{
		args->hdoc = 0;
		args->infile = ft_strdup(argv[0]);
		if (!args->infile)
			return (-1);
		args->mode = O_TRUNC;
	}
	return (0);
}

int	fill_data(int argc, char **argv, t_data *args)
{
	if (assign_mode(argv, args) == -1)
		return (-1);
	args->fdin = open(args->infile, O_RDONLY);
	args->fdout = open(argv[argc - 1], O_WRONLY | O_CREAT | args->mode, 0644);
	args->lst = fill_list(argc - 1 - args->hdoc, argv + 1 + args->hdoc, args);
	if (!args->lst)
		return (-1);
	return (0);
}
