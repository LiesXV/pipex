/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:58 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/03/01 15:19:13 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_lstprint(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		while (lst->cmd[i])
		{
			ft_printf("%s ", lst->cmd[i]);
			i++;
		}
		ft_printf(" [path : %s]\n", lst->path);
		i = 0;
		lst = lst->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	args;

	if (argc < 5)
		return (ft_printf("arguments insuffisants\n."), 0);
	args.env = get_env(env);
	if (!args.env)
		return (ft_printf("environment variables not parsed\n"), 0);
	if (fill_data(argc - 1, argv + 1, &args) == -1)
		return (ft_printf("data not filled\n"), 0);
	ft_lstprint(args.lst);
	dup2(args.fdin, STDIN_FILENO);
	dup2(args.fdout, STDOUT_FILENO);
	redir(args.lst, env, args.fdin);
	args.lst = args.lst->next;
	while (args.lst->next)
	{
		redir(args.lst, env, 1);
		args.lst = args.lst->next;
	}
	exec(args.lst, env);
}
