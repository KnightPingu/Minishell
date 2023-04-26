/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:43:04 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/26 17:35:49 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	does_cmd_exist(char *str)
{
	if (access(str, F_OK | X_OK) != -1)
		return (1);
	else
		return (0);
}

static void	put_path_cmd(char **cmd)
{
	int		i;
	char	*tmp;
	t_pipex	*p;

	i = 0;
	tmp = NULL;
	p = g_sh->pipex;
	while (p->paths[i])
	{
		tmp = ft_strjoin(p->paths[i], *cmd);
		if (does_cmd_exist(tmp))
		{
			free(*cmd);
			*cmd = ft_strdup(tmp);
			free(tmp);
			return ;
		}
		free(tmp);
		if (i == p->nbr_paths - 1)
			ft_error("Command was not found\n", 0);
		i++;
	}
}

void	ft_parse_cmds(void)
{
	t_pipex	*p;
	t_pcmd	*head;
	
	p = g_sh->pipex;
	head = p->lst;
	while (p->lst)
	{
		if (!does_cmd_exist(p->lst->content[0]))
			put_path_cmd(&p->lst->content[0]);
		p->lst = p->lst->next;
	}
	p->lst = head;
}
