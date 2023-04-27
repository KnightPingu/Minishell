/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:42:37 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/04/28 01:23:34 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_exit_signal(int EXIT_MACRO)
{
	if (EXIT_MACRO != 0)
		ft_exit(EXIT_MACRO);	
}

void	ft_parent_close(int pos)
{
	t_pipex	*p;

	p = g_sh->pipex;
	check_exit_signal(p->exit_macro);
	if (pos == 0)
	{
		//ft_close(&p->infile);
		ft_close(&p->pipefd[0][1]);
	}
	else if (pos == p->nbr_fork - 1)
	{
		ft_close(&p->pipefd[pos - 1][0]);
		//ft_close(&p->outfile);
	}
	else
	{
		ft_close(&p->pipefd[pos - 1][0]);
		ft_close(&p->pipefd[pos][1]);
	}
}
