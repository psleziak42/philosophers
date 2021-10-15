NAME	= philo
CC		= gcc
SRCS	= philo.c philo_forks.c philo_init.c philo_thread_operations.c philo_utils.c
OBJS	= $(SRCS:.c=.o)
CFLAGS	= -Wall -Werror -Wextra
LDFLAGS	= -fsanitize=address

.SILENT:
all: $(NAME)

$(NAME): $(OBJS)
	echo "\033[0;37m[ .. ] compiling\033[0m"
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@
	mkdir -p OBJ
	echo "\033[0;37m[ .. ] OBJ folder created\033[0m"
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@
	echo "\033[0;37m[ .. ] .o files copied to OBJ\033[0m"
	mv $^ OBJ
	echo '\033[32m[ ✔ ]' "execute '$(NAME)' created" '\033[0m'

clean:
	rm -fr OBJ
	echo "\033[31m[ x ] objects removed \033[0m"

fclean: clean
	rm -fr $(NAME)
	echo "\033[31m[ x ] executive '$(NAME)' removed \033[0m"

re: fclean $(NAME)

.PHONY: clean fclean all
