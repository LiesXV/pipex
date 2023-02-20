/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:58 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/20 16:08:55 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	separti(t_data *args)
// {
// 	pid_t	pid1;
// 	pid_t	pid2;

// 	if (pipe(fd) == -1)
// 		ft_printf("pipe\n");
	
// 	pid1 = fork();
// 	if (pid1 == -1)
// 		return (ft_printf("3"), 1);
	
// 	if (pid1 == 0)
// 	{
// 		ft_printf("j'entre dans l'enfant\n");
// 		close(pipe[0]);
// 		dup2(fd1, STDIN_FILENO);
// 		dup2(pipe[1], STDOUT_FILENO);
// 		close(pipe[1]);
// 		execve(args->path1, args->cmd1, NULL);
// 		ft_printf("execve\n");
// 		exit(0);
// 	}

// 	pid2 = fork();
// 	if (pid2 < 0)
// 		return (ft_printf("4"), 1);

// 	if (pid2 == 0)
// 	{
// 		ft_printf("j'entre dans le second fils\n");
// 		close(pipe[1]);
// 		dup2(fd2, STDOUT_FILENO);
// 		dup2(pipe[0], STDIN_FILENO);
// 		close(pipe[0]);
// 		execve(args->path2, args->cmd2, NULL);
// 		ft_printf("execve 2\n");
// 		exit(0);
// 	}
// 	close(pipe[0]);
// 	close(pipe[1]);
// 	close (fd2);
// 	close (fd1);
// 	ft_printf("test\n");
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	ft_printf("je sors des fils\n");
// 	return (0);
// }


int	main(int argc, char **argv, char **env)
{
	t_data	args;

	if (argc != 5)
		return (0);
	if (pipe(args.pipe) == -1)
		return (ft_printf("pipe not created\n", 0));
	args.env = get_env(env);
	if (!args.env)
		return (ft_printf("!args.env\n"), 0);
	if (fill_data(argv, &args) == -1)
		return (ft_printf("data not filled\n"), 0);
	args.fd1 = open(args.infile, O_RDONLY);
	if (args.fd1 == -1)
		return (ft_printf("fd1 not opened\n"), 0);
	args.fd2 = open(args.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (args.fd2 == -1)
		return (ft_printf("fd2 not opened\n"), 0);
	enter_process(&args, env);
}
