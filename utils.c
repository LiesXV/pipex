/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:07:15 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/03/09 15:42:22 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_data *args)
{
	if (args->hdoc == 1 && args->limiter)
		free(args->limiter);
	if (args->infile != NULL)
		free(args->infile);
	if (args->env != NULL)
		free_split(args->env);
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
