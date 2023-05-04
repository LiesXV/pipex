/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:46:10 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/04/27 18:14:03 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../pipex.h"

t_list	*new_error(t_data *args, t_list *new, char *cmd)
{
	ft_printf("command not found: %s\n", cmd);
	free_split(new->cmd);
	free(new);
	return (ft_lstnew("sleep 0", args));
}

t_list	*ft_lstnew(char *cmd, t_data *args)
{
	t_list	*new;

	if (args->cpt == 1)
	{
		args->cpt = 0;
		return (ft_lstnew("sleep 0", args));
	}
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->cmd = ft_split_pipex(cmd, ' ');
	if (!new->cmd || !new->cmd[0])
		return (new_error(args, new, cmd));
	new->path = get_path(args->env, new->cmd[0]);
	if (!new->path)
		return (new_error(args, new, cmd));
	new->next = NULL;
	return (new);
}
