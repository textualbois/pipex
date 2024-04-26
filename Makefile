NAME = pipex

SRCS = pipex.c executioner.c utils.c get_path.c manage_fd.c here_doc.c gnl.c error.c command_parser.c

B_SRCS = pipex.c executioner.c utils.c get_path.c manage_fd.c here_doc.c gnl.c error.c command_parser.c

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make all bonus -C ./libft/
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

bonus: fclean $(B_OBJS)
	make all bonus -C ./libft/
	$(CC) $(CFLAGS) $(B_OBJS) libft/libft.a -o ${NAME}


clean:
	make clean -C ./libft/
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re




#$%.o: %.c
#	$(CC) $(CFLAGS) -g -c $< -o $@./

#libft:
#	make -C ./libft/
