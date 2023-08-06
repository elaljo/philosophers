NAME = philo

CC = cc

#CFLAGS = -Wall -Werror -Wextra -pthread
CFLAGS = -Wall -Werror -Wextra -pthread -fsanitize=thread

RM = rm -rf

C_FILES = philo.c\
					check_args.c\
					init_funcs.c\
					utils1.c\
					

OBJ = ${C_FILES:.c=.o}

all: ${NAME}

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	@echo "Removing all .o files"
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME} ${OBJ}

re : fclean all

.PHONY : all clean fclean re
