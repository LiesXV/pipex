/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:45:04 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/03/10 12:34:53 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*node = NULL;
	t_list	*next_node = NULL;

	if (lst == NULL)
		return ;
	node = *lst;
	while (node)
	{
		next_node = node->next;
		if (node->cmd)
			free_split(node->cmd);
		if (node->path)
			free(node->path);
		free(node);
		node = next_node;
	}
	*lst = NULL;
	return ;
}
