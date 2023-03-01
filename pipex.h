/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:36:10 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/03/01 15:38:15 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

////////////////// PROCESSES /////////////////////////

void	redir(t_list *lst, char **env, int fdin);
void	exec(t_list *lst, char **env);

////////////////// PARSING //////////////////////////

int		fill_data(int argc, char **argv, t_data *args);
char	*get_path(char **path, char *cmd);

/////////////////// GET_ENV ////////////////////////

char	**get_env(char **env);

//////////////////// UTILS /////////////////////////

void	free_all(t_data *args);
void	read_input(t_data *args);

#endif