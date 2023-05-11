/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:11:45 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/05/11 17:10:31 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*********************      MACROS     ************************/

# define EXIT_PWD_FAILURE 10
# define EXIT_CHDIR_FAILURE 11

/*********************     FUNCTION    ************************/

// ECHO.C
void	ft_echo(char **strs);

// ENV.C
void	ft_env(void);

// EXPORT.C
void	ft_export(char **strs);

// EXPORT_UTILS.C
void	sort_env_ascii(void);
void	print_export(void);

// PWD.C
char	*ft_pwd(void);

// UNSET.C
void	ft_unset(char **vars);

// EXIT.C
void	ft_exit_builtin(void);

// CD.C
void	ft_cd(char *str);

// IS_BUILTIN.C
int		is_builtin(char *cmd);
void	exec_builtin(char *cmd, char **arg);

void	print_array(char **array);

#endif