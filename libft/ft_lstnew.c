/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:46:10 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/04/17 12:28:22 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../pipex.h"

t_list	*ft_lstnew(char *cmd, t_data *args)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->cmd = ft_split_pipex(cmd, ' ');
	if (!new->cmd)
		return (free(new), ft_lstnew("sleep 0", args));
	new->path = get_path(args->env, new->cmd[0]);
	if (!new->path)
		return (free_split(new->cmd), free(new), ft_lstnew("sleep 0", args));
	new->next = NULL;
	return (new);
}
