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
	close(1);
	close(0);
	if (args->limiter)
		free(args->limiter);
	if (args->infile)
		free(args->infile);
	if (args->env)
		free_split(args->env);
	if (&args->lst)
		ft_lstclear(&args->lst);
}
