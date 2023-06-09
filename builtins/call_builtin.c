/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:47:02 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/06/01 22:15:31 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(const char *cmd)
{
	if (compare_keys(cmd, "cd") || compare_keys(cmd, "echo")
		|| compare_keys(cmd, "env") || compare_keys(cmd, "exit")
		|| compare_keys(cmd, "unset") || compare_keys(cmd, "pwd")
		|| compare_keys(cmd, "export"))
		return (1);
	return (0);
}

void	exec_builtin(const char *cmd, const char **arg)
{
	update_last_cmd(arg);
	g_sh->pipex->dup_stdout = ft_dup(STDOUT_FILENO);
	if (!builtin_redirection())
	{
		set_exit(1);
		restore_stdout(g_sh->pipex->dup_stdout);
		return ;
	}
	if (compare_keys(cmd, "cd"))
		cd_builtin(arg[1]);
	else if (compare_keys(cmd, "echo"))
		echo_builtin(&arg[1]);
	else if (compare_keys(cmd, "env"))
		env_builtin(&arg[1]);
	else if (compare_keys(cmd, "exit"))
		exit_builtin(&arg[1]);
	else if (compare_keys(cmd, "unset"))
		unset_builtin(&arg[1]);
	else if (compare_keys(cmd, "pwd"))
		pwd_builtin();
	else if (compare_keys(cmd, "export"))
		export_builtin(&arg[1]);
	restore_stdout(g_sh->pipex->dup_stdout);
}
