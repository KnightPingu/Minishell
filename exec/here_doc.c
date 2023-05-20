/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:00:32 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/05/20 01:04:33 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc_catch_kill(int sig)
{
	if (sig == SIGINT)
	{
		g_sh->pipe_exit = 1;
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	here_doc(char *end_token)
{
	t_pipex	*p;
	char	*str;
	char	*prompt;

	set_signals(SIG_HERE);
	p = g_sh->pipex;
	p->here_doc = ft_open(TMP_FILE, HEREDOC_FLAGS, 0644);
	prompt = ft_strjoin(end_token, "> ");
	if (!prompt)
		ft_exit(EXIT_GNL_FAILURE);
	while (1)
	{
		str = readline(prompt);
		if (!str)
			break ;
		if (compare_keys(str, end_token))
			break ;
		ft_putendl_fd(str, p->here_doc);
		free(str);
	}
	free(str);
	free(prompt);
	ft_close(&p->here_doc);
	set_signals(g_sh->is_child);
}

void	ft_here_doc_exp(char *end_token)
{
	t_pipex	*p;
	char	*str;
	char	*prompt;

	set_signals(SIG_HERE);
	p = g_sh->pipex;
	p->here_doc = ft_open(TMP_FILE, HEREDOC_FLAGS, 0644);
	prompt = ft_strjoin(end_token, "> ");
	if (!prompt)
		ft_exit(EXIT_GNL_FAILURE);
	while (1)
	{
		str = readline(prompt);
		if (!str)
			break ;
		if (compare_keys(str, end_token))
			break ;
		expand_heredoc(&str);
		ft_putendl_fd(str, p->here_doc);
		free(str);
	}
	free(str);
	free(prompt);
	ft_close(&p->here_doc);
	set_signals(g_sh->is_child);
}
