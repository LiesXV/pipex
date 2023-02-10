/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:58 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/10 16:11:42 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	separti(t_data *args)
{
	pid_t pid1;
	int ex;

	// ft_printf("cmd1[0] : %s", args->cmd1[0]);
	pid1 = fork();
	if (pid1 == -1)
		return (ft_printf("3"), 1);
	
	if (pid1 == 0)
	{
		ex = execve(args->cmd1[0], args->cmd1, NULL);
		if (ex == -1)
			return (ft_printf("2"), 1);
	}
	else
	{
		waitpid(pid1, NULL, 0);
		// ft_printf("\nfin du execve bebew :) \n");
	}	
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	args;
	
	if (argc != 3)
		return (0);
	args.env = get_path(env);
	int i = 0;
	while (args.env[i])
	{
		ft_printf("%s\n", args.env[i]);
		i++;
	}
	parsing(argv + 1, &args);
	separti(&args);
}
