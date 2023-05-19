/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:55:29 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/05/19 19:26:19 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	arraylen(const char **array)
{
	size_t	i;

	i = 0;
	if (!array || !*array)
		return (0);
	while (array[i])
		i++;
	return (i);
}


// Compares 2 strings with strncmp and strings length.
int	compare_keys(const char *key, const char *needle)
{
	size_t	key_len;
	size_t	needle_len;

	if (!key || !needle)
		return (0);
	key_len = ft_strlen(key);
	needle_len = ft_strlen(needle);
	if ((key_len == needle_len) && ft_strncmp(key, needle, key_len) == 0)
		return (1);
	return (0);
}

// Exits current program only if it is a child
void	exit_only_child(int exit_code)
{
	t_pipex	*p;

	p = g_sh->pipex;
	if (p->nbr_fork > 0)
		exit(exit_code);
}
