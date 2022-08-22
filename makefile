CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES = minishell.c \
		  sources/parsing/ft_len_env_wl.c \
		  sources/parsing/ft_len_env_ws.c \
		  sources/parsing/ft_remove_env_search.c \
		  sources/parsing/ft_remove_env.c \
		  sources/parsing/ft_search_env.c \
		  sources/utils/ft_strndup.c \
		  sources/utils/ft_strnjoin.c \

OBJECTS = $(SOURCES:.c=.o)
NAME = minishell

all: $(NAME)

minishell: minishell.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o : %.c
	$(CC) -c $(CFLAGS) $?

libft :
	make -C libft

clean : 
	rm -f $(OBJECTS)
	make -C libft clean

fclean : clean
	rm -f $(NAME) libft/libft.a

re : fclean all

.PHONY : all libft clean fclean all bonus
