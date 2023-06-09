/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:56:59 by dopeyrat          #+#    #+#             */
/*   Updated: 2023/05/29 17:27:36 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	catch_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	if (!g_sh->pipex || !g_sh->pipex->is_in_child)
	{
		g_sh->pipe_exit = 1;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	catch_here_sigint(int sig)
{
	(void)sig;
	restore_stdin(g_sh->pipex->dup_stdin);
	g_sh->here_doc_status = 1;
	g_sh->pipe_exit = 1;
	write(1, "\n", 1);
}

void	set_signals(int state)
{
	if (state == DEFAULT)
	{
		signal(SIGINT, catch_sigint);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (state == SIG_HERE)
	{
		signal(SIGINT, catch_here_sigint);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (state == PARENT)
	{
		signal(SIGINT, catch_sigint);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (state == CHILD)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
	}
}
