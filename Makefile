# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 17:02:21 by dopeyrat          #+#    #+#              #
#    Updated: 2023/05/15 14:46:12 by fgeorgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN			= main/
LEX				= lexer/
EXEC			= exec/
BUILTINS 		= builtins/
LINKED_LISTS	= linked_lists/

SRCS	=	$(MAIN)main.c \
			$(MAIN)free.c \
			$(MAIN)init.c \
			$(MAIN)error.c \
			$(EXEC)exec.c \
			$(EXEC)exec_utils.c \
			$(EXEC)fork.c \
			$(EXEC)fork_utils.c \
			$(EXEC)free.c \
			$(EXEC)here_doc.c \
			$(EXEC)init.c \
			$(EXEC)parsing.c \
			$(EXEC)pipe.c \
			$(EXEC)close_pipes.c \
			$(EXEC)utils.c \
			$(EXEC)pipex.c \
			$(EXEC)env.c \
			$(EXEC)redir.c \
			$(EXEC)protections.c \
			$(LINKED_LISTS)linked_list_env.c \
			$(LINKED_LISTS)linked_list_cmd.c \
			$(LINKED_LISTS)linked_list_redir.c \
			$(BUILTINS)echo.c \
			$(BUILTINS)env.c \
			$(BUILTINS)pwd.c \
			$(BUILTINS)cd.c \
			$(BUILTINS)unset.c \
			$(BUILTINS)export.c \
			$(BUILTINS)export_utils.c \
			$(BUILTINS)call_builtin.c \
			$(BUILTINS)redirections_builtins.c \
			$(BUILTINS)exit.c \
			$(LEX)lexer.c \
			$(LEX)lexer_utils.c \
			$(LEX)shell_split.c \
			$(LEX)tokenize.c \
			$(LEX)expander.c \
			$(LEX)post_expander.c \
			$(LEX)remove_quotes.c \
			$(LEX)parser.c \
			$(LEX)new_expander.c \
			$(LEX)expander_utils.c \

OBJS	=	${SRCS:.c=.o}

NAME	= minishell

LIBFT	= LIBFT/libft.a

CC		= gcc

READL	= -L/usr/local/lib -I/usr/local/include -lreadline -L $(shell brew --prefix readline)/lib -I $(shell brew --prefix readline)/include

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address -g

all:	${NAME}

$(LIBFT):
	make -C LIBFT/

${NAME}:	$(LIBFT) ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} -ILIBFT -LLIBFT -lft ${READL} ${OBJS}

clean:
	rm -f ${OBJS}
	make -C LIBFT/ clean

fclean:	clean
	rm -f ${NAME}
	make -C LIBFT/ fclean

re:	fclean all

.PHONY:	re clean fclean all libft
