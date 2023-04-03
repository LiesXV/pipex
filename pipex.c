/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:58 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/03/31 13:26:55 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_process(t_list *lst)
{
	while (lst)
	{
		wait(NULL);
		lst = lst->next;
	}
}

void	process(t_data *args, char **env)
{
	int		pid1;
	t_list	*clone;

	clone = args->lst;
	if (args->fdin != -1)
	{
		if (dup2(args->fdin, STDIN_FILENO) == -1)
			exit(1);
		close(args->fdin);
	}
	if (args->fdout != -1)
	{
		if (dup2(args->fdout, STDOUT_FILENO) == -1)
			exit(1);
		close(args->fdout);
	}
	while (clone->next)
	{
		redir(clone, env);
		clone = clone->next;
	}
	pid1 = fork();
	if (pid1 == 0)
		exec(clone, env);
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
	{
		free_all(&args);
		ft_printf("data unfilled\n");
		return (0);
	}
	process(&args, env);
	close(STDIN_FILENO);
	wait_process(args.lst);
	free_all(&args);
	ft_lstclear(&args.lst);
	get_next_line(-1);
	return (0);
}
