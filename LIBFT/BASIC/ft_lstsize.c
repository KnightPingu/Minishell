/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:28:41 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/11/23 09:28:43 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	if (lst == 0)
		return (0);
	if (lst->next == 0)
		return (1);
	return (1 + ft_lstsize(lst->next));
}
