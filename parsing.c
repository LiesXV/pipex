/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:56:14 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/21 15:43:02 by ibenhaim         ###   ########.fr       */
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

// int	fill_list(t_list **lst, int argc, char **argv)
// {
// 	int 	i;

// 	i = 0;
// 	while (i < argc - 1)
// 	{
// 		(*lst) = ft_lstnew(argv[i]);
// 		ft_printf("%s\n", (*lst)->cmd);
// 		if (!(*lst)->cmd)
// 			return (ft_lstclear(lst), -1);
// 		(*lst) = (*lst)->next;
// 		i++;
// 	}
// 	return (1);
// }

t_list	*fill_list(int argc, char **argv)
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
			stack_a = ft_lstnew(split);
			if (!stack_a)
				return (ft_lstclear(&stack_a), NULL);
		}
		else
		{
			cell = ft_lstnew(split);
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
	args->infile = ft_strdup(argv[0]);
	if (!args->infile)
		return (-1);
	args->outfile = ft_strdup(argv[argc - 1]);
	if (!args->outfile)
		return (-1);
	args->list = fill_list(argc - 1, argv + 1);
	//ft_lstprint(args->list);
	/*args->path1 = get_path(args->env, args->cmd1[0]);
	if (!args->path1)
		return (-1);
	args->path2 = get_path(args->env, args->cmd2[0]);
	if (!args->path2)
		return (-1);*/
	return (0);
}