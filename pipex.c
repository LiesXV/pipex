/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:35:58 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/16 14:12:45 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **path, char *cmd)
{
	char	*test;
	int		i;
	int		result;
	
	result = -1;
	i = 0;
	test = NULL;
	while (path[i] && result == -1)
	{
		test = ft_strjoin(path[i], "/");
		if (!test)
			return (free(test), NULL);
		test = ft_strjoin(test, cmd);
		if (!test)
			return (free(test), NULL);
		if (access(test, F_OK | X_OK) == 0)
			result = 1;
		if (result == -1)
			free(test);
		i++;
	} 
	return (test);
}

int	separti(t_data *args)
{
	pid_t pid1;
	int ex;

	pid1 = fork();
	if (pid1 == -1)
		return (ft_printf("3"), 1);
	
	if (pid1 == 0)
	{
		ex = execve(args->path, args->cmd1, NULL);
		if (ex == -1)
			return (ft_printf("2"), 1);
	}
	else
	{
		waitpid(pid1, NULL, 0);
	}	
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	args;
	
	if (argc != 3)
		return (0);
	args.env = get_env(env);
	if (!args.env)
		return (ft_printf("!args.env"), 0);
	parsing(argv, &args);
	args.path = get_path(args.env, args.cmd1[0]);
	separti(&args);
}
