/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:07:15 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/03/01 15:46:09 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_data *args)
{
	if (args->limiter != NULL)
		free(args->limiter);
	if (args->infile)
		free(args->infile);
	if (args->env)
		free_split(args->env);
	close(args->pipe[0]);
	close(args->pipe[1]);
	close(args->fdin);
	close(args->fdin);
}

void	read_input(t_data *args)
{
	int		file;
	char	*line;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (!line)
			exit(1);
		if (!ft_strncmp(args->limiter, line, ft_strlen(args->limiter)))
			break ;
		write(file, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(file);
	args->infile = ft_strdup(".heredoc_tmp");
}
