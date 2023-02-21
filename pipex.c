/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:58 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/21 15:36:12 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_lstprint(t_list *lst)
{
	int i;

	i = 0;
	while(lst)
	{
		while (i < 2)
		{
			ft_printf("%s ", lst->cmd[i]);
			i++;
		}
		ft_printf("\n");
		i = 0;
		lst = lst->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	args;

	if (argc < 5)
		return (ft_printf("arguments insuffisants\n."), 0);
	if (pipe(args.pipe) == -1)
		return (ft_printf("pipe not created\n", 0));
	args.env = get_env(env);
	if (!args.env)
		return (ft_printf("environment variables not parsed\n"), 0);
	if (fill_data(argc - 1, argv + 1, &args) == -1)
		return (free_all(&args), ft_printf("data not filled\n"), 0);
	args.fd1 = open(args.infile, O_RDONLY);
	if (args.fd1 == -1)
		return (free_all(&args), ft_printf("fd1 not opened\n"), 0);
	args.fd2 = open(args.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (args.fd2 == -1)
		return (free_all(&args), ft_printf("fd2 not opened\n"), 0);
	enter_process(&args);
	free_all(&args);
}
