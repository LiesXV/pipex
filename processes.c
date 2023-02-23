/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:33:37 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/23 15:55:51 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_list *lst, char **env)
{
	ft_printf("%s\n", lst->path);
	execve(lst->path, lst->cmd, env);
	ft_printf("first exec failed\n");
	exit (0);
}

// void	second_exec(t_data *args)
// {
// 	close(args->pipe[1]);
// 	dup2(args->fd2, STDOUT_FILENO);
// 	dup2(args->pipe[0], STDIN_FILENO);
// 	close(args->pipe[0]);
// 	execve(args->path2, args->cmd2, env);
// 	ft_printf("second exec failed\n");
// 	exit (0);
// }

// int	enter_process(t_data *args, char **env)
// {
// 	pid_t	pid1;
// 	int		pipe1[2];
// 	int		pipe2[2];
	
// 	if ((pipe(pipe1) == -1) || (pipe(pipe2) == -1))
// 		return (ft_printf("pipes not created\n", 0));
// 	pid1 = fork();
// 	if (pid1 < 0)
// 		return (ft_printf("no pid1\n", 0));
// 	else if (pid1 == 0)
// 	{
// 		close(pipe1[0]);
// 		dup2(args->fd1, STDIN_FILENO);
// 		dup2(pipe1[1], STDOUT_FILENO);
// 		close(pipe1[0]);
// 		exec(args->lst, env);
// 	}
// 	args->lst = args->lst->next;
// 	while (args->lst)
// 	{
 
// 	}
// }

void	redir(t_list *lst, char **env, int fdin)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		if (fdin == STDIN_FILENO)
			exit(1);
		else
			exec(lst, env);
	}
}
