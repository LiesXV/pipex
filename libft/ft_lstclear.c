/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:45:04 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/02/21 15:40:34 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*node;
	t_list	*next_node;

	if (lst == NULL)
		return ;
	node = *lst;
	while (node)
	{
		next_node = node->next;
		free_split(node->cmd);
		free(node);
		node = next_node;
	}
	*lst = NULL;
	return ;
}
