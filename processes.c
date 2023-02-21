/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:33:37 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/21 14:19:43 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_exec(t_data *args)
{
	close(args->pipe[0]);
	dup2(args->fd1, STDIN_FILENO);
	dup2(args->pipe[1], STDOUT_FILENO);
	close(args->pipe[1]);
	// execve(args->path1, args->cmd1, env);
	ft_printf("first exec failed\n");
	exit (0);
}

void	second_exec(t_data *args)
{
	close(args->pipe[1]);
	dup2(args->fd2, STDOUT_FILENO);
	dup2(args->pipe[0], STDIN_FILENO);
	close(args->pipe[0]);
	// execve(args->path2, args->cmd2, env);
	ft_printf("second exec failed\n");
	exit (0);
}

int	enter_process(t_data *args)
{
	pid_t	pid1;
	pid_t	pid2;
	
	pid1 = fork();
	if (pid1 == -1)
		return (ft_printf("fork pid1 failed\n"), -1);
	if (pid1 == 0)
		first_exec(args);
	pid2 = fork();
	if (pid2 == -1)
		return (ft_printf("fork pid1 failed\n"), -1);
	if (pid2 == 0)
		second_exec(args);
	close(args->pipe[0]);
	close(args->pipe[1]);
	close(args->fd1);
	close(args->fd2);
	return (0);
}
