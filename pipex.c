/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:58 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/04/17 12:58:17 by ibenhaim         ###   ########.fr       */
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

void	make_dups(t_data *args)
{
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
}

void	process(t_data *args, char **env)
{
	int		pid1;
	t_list	*clone;

	make_dups(args);
	clone = args->lst;
	while (clone->next)
	{
		if (args->cpt == 1)
		{
			clone = clone->next;
			args->cpt = 0;
		}
		else
		{
			redir(clone, env);
			clone = clone->next;
		}
	}
	pid1 = fork();
	if (pid1 == -1)
		exit(1);
	if (pid1 == 0)
		exec(clone, env);
}

int	main(int argc, char **argv, char **env)
{
	t_data	args;

	if (argc < 5)
		return (ft_putstr_fd("arguments insuffisants\n", 2), 0);
	args.env = get_env(env);
	if (!args.env)
		return (ft_putstr_fd("environment variables not parsed\n", 2), 0);
	if (fill_data(argc - 1, argv + 1, &args) == -1)
	{
		free_all(&args);
		ft_putstr_fd("data unfilled\n", 2);
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
