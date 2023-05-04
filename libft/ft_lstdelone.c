/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:24:43 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/01/30 17:38:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_last(t_list *lst, t_data *args)
{
	lst = ft_lstmlast(lst);
	if (lst->next->cmd)
		free_split(lst->next->cmd);
	if (lst->next->path)
		free(lst->next->path);
	free(lst->next);
	lst->next = ft_lstnew("sleep 0", args);
	lst->next->next = NULL;
}
