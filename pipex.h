/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:36:10 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/16 14:16:43 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/wait.h>

typedef struct	s_data
{
	char	*path;
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	**env;
}				t_data;

void	parsing(char **argv, t_data *args);
char	**get_env(char **env);

#endif