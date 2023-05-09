/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:07:15 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/04/27 13:11:03 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_data *args)
{
	if (args->hdoc == 1 && args->limiter)
		free(args->limiter);
	if (args->hdoc == 0 && args->infile)
		free(args->infile);
	if (args->env)
		free_split(args->env);
	if (&args->lst)
		ft_lstclear(&args->lst);
}

void	read_input(t_data *args, int fd[2])
{
	char	*line;

	while (1)
	{
		write(2, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			close(fd[0]);
			close(fd[1]);
			exit(1);
		}
		if (!ft_strncmp(args->limiter, line, ft_strlen(args->limiter)))
		{
			close(fd[0]);
			close(fd[1]);
			exit(1);
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(fd[0]);
	close(fd[1]);
}
