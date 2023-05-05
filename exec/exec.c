/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:44:26 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/05/05 17:31:42 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_child(int pos, t_cmd *cmd, t_pipex *p)
{
	p->outfile = open_outfile(cmd);
	p->infile = open_infile(cmd);
	ft_close_pipes(pos, p);
	if (pos == 0)
		ft_first_child(p);
	else if (pos == p->nbr_pipe)
		ft_last_child(pos, p);
	else
		ft_middle_child(pos, p);
	ft_execve(cmd->cmd, p->env_array);
}

void	ft_exec(void)
{
	t_pipex	*p;
	t_cmd	*cmd;
	int		i;

	i = 0;
	p = g_sh->pipex;
	cmd = g_sh->cmd;
	while (cmd)
	{
		ft_pipe(i);
		ft_fork(i);
		if (p->pids[i] == 0)
			ft_child(i, cmd, p);
		ft_parent_close(i, p);
		cmd = cmd->next;
		i++;
	}
}
