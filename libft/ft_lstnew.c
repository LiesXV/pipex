/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:46:10 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/04/03 10:45:18 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../pipex.h"

int	add_newcmd(char ***cmd, char **path, char **env)
{
	*cmd = ft_split_pipex("sleep 0", ' ');
	if (!cmd)
		return (-1);
	*path = get_path(env, "sleep");
	if (!path)
		return (free_split(*cmd), -1);
	return (0);
}

t_list	*ft_lstnew(char *cmd, t_data *args)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->cmd = ft_split_pipex(cmd, ' ');
	if (!new->cmd)
	{
		if (add_newcmd(&new->cmd, &new->path, args->env) == -1)
			return (NULL);
		return (new);
	}
	new->path = get_path(args->env, new->cmd[0]);
	if (!new->path)
	{
		free_split(new->cmd);
		if (add_newcmd(&new->cmd, &new->path, args->env) == -1)
			return (NULL);
		return (new);
	}
	new->next = NULL;
	return (new);
}
