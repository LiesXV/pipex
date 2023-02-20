/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:36:10 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/20 15:49:17 by ibenhaim         ###   ########.fr       */
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
	int		fd1;
	int		fd2;
	int		pipe[2];
	char	*path1;
	char	*path2;
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	**env;
}				t_data;

int	enter_process(t_data *args, char **env);

////////////////// PARSING //////////////////////////

int	fill_data(char **argv, t_data *args);

/////////////////// GET_ENV ////////////////////////

char	**get_env(char **env);

//////////////////// UTILS /////////////////////////

char	*ft_strjoin(char const *s1, char const *s2);

#endif