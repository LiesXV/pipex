/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:36:10 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/21 15:25:56 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

///////////////// STRUCT /////////////////////////

typedef struct	s_data
{
	int				fd1;
	int				fd2;
	int				pipe[2];
	char			*path1;
	char			*path2;
	char			*infile;
	char			*outfile;
	t_list			*list;
	char			**env;
}				t_data;

void ft_lstprint(t_list *lst);

////////////////// PROCESSES /////////////////////////

int	enter_process(t_data *args);

////////////////// PARSING //////////////////////////

int	fill_data(int argc, char **argv, t_data *args);

/////////////////// GET_ENV ////////////////////////

char	**get_env(char **env);

//////////////////// UTILS /////////////////////////

void free_all(t_data *args);

#endif