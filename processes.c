/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:33:37 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/03/01 14:56:52 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_list *lst, char **env)
{
	//ft_printf("%s\n", lst->path);
	execve(lst->path, lst->cmd, env);
	ft_printf("first exec failed\n");
	exit (0);
}

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
