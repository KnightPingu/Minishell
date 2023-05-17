/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopeyrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:56:59 by dopeyrat          #+#    #+#             */
/*   Updated: 2023/05/17 13:57:15 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	catch_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	if (!g_sh->pipex || !g_sh->pipex->is_in_child)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_sh->pipe_exit = 1;
	}
	else
	{
		g_sh->pipe_exit = 130;
	}
}

void	catch_sigquit(int sig)
{
	(void)sig;
	write(1, "Quit: 3\n", 8);
	g_sh->pipe_exit = 131;
}

void	catch_here_sigint(int sig)
{
	(void)sig;
	close(0);
	g_sh->here_doc_status = 1;
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
		signal(SIGQUIT, catch_sigquit);
	}
	else if (state == CHILD)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
	}
}