/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:36:10 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/10 16:10:05 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/wait.h>

typedef struct	s_data
{
	char	*file1;
	char	**cmd1;
	char	**env;
}				t_data;

void	parsing(char **argv, t_data *args);
char	**get_path(char **env);

#endif