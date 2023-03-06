/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:58 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/03/06 15:31:52 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	list_print(t_list *lst)
{
	int	row;

	while (lst)
	{
		row = 0;
		ft_printf("path : %s\n", lst->path);
		while (lst->cmd[row])
		{
			ft_printf("cmd = [%s]\n", lst->cmd[row]);
			row++;
		}
		lst = lst->next;
	}
}

void	process(t_data *args, char **env)
{
	int		pid1;
	t_list	*clone;
		
	clone = args->lst;
	dup2(args->fdin, STDIN_FILENO);
	dup2(args->fdout, STDOUT_FILENO);
	redir(clone, env, args->fdin);
	clone = clone->next;
	while (clone->next)
	{
		redir(clone, env, 1);
		clone = clone->next;
	}
	pid1 = fork();
	if (pid1 == 0)
		exec(clone, env);
	wait(NULL);
}

int	main(int argc, char **argv, char **env)
{
	t_data	args;

	if (argc < 5)
		return (ft_printf("arguments insuffisants\n"), 0);
	args.env = get_env(env);
	if (!args.env)
		return (ft_printf("environment variables not parsed\n"), 0);
	if (fill_data(argc - 1, argv + 1, &args) == -1)
		return (free_all(&args), ft_lstclear(&args.lst), ft_printf("data not filled\n"), 0);
	process(&args, env);
	free_all(&args);
	list_print(args.lst);
	ft_lstclear(&args.lst);
	return (0);
}
