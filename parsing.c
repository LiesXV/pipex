/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:56:14 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/04/27 17:46:09 by ibenhaim         ###   ########.fr       */
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

	i = -1;
	test = ft_strdup(cmd);
	if (!test)
		return (NULL);
	if (cmd != NULL && ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (test);
		return (NULL);
	}
	while (path[++i])
	{
		free(test);
		test = join_cmd(path[i], cmd);
		if (!test)
			return (NULL);
		if (access(test, F_OK | X_OK) >= 0)
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
	args->infile = ft_strdup(argv[0]);
	if (!args->infile)
		return (-1);
	args->mode = O_TRUNC;
	args->limiter = NULL;
	return (0);
}

int	fill_data(int argc, char **argv, t_data *args)
{
	args->cpt = 0;
	args->hdoc = assign_mode(argv, args);
	if (args->hdoc == -1)
		return (ft_printf("error"), free_and_exit(args), 0);
	else
	{
		args->fdin = open(args->infile, O_RDONLY);
		if (args->fdin < 0)
		{
			ft_printf("%s: No such file or directory\n", args->infile);
			args->cpt = 1;
		}
	}
	args->lst = fill_list(argc - 1 - args->hdoc, argv + 1 + args->hdoc, args);
	if (!args->lst)
		return (-1);
	args->fdout = open(argv[argc - 1], O_WRONLY | O_CREAT | args->mode, 0644);
	if (args->fdout == -1)
	{
		ft_printf("%s: No such file or directory\n", argv[argc - 1]);
		del_last(args->lst, args);
	}
	return (0);
}
