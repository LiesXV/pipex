/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:58 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/03/01 15:42:35 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	args;

	if (argc < 5)
		return (ft_printf("arguments insuffisants\n."), 0);
	args.env = get_env(env);
	if (!args.env)
		return (ft_printf("environment variables not parsed\n"), 0);
	if (fill_data(argc - 1, argv + 1, &args) == -1)
		return (free_all(&args), ft_printf("data not filled\n"), 0);
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
	return (0);
}
