/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:07:15 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/21 12:16:40 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_data *args)
{
	free(args->path1);
	free(args->path2);
	free(args->infile);
	free(args->outfile);
	free_split(args->cmd1);
	free_split(args->cmd2);
	free_split(args->env);
	close(args->pipe[0]);
	close(args->pipe[1]);
	close(args->fd1);
	close(args->fd2);
}