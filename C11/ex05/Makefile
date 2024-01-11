NAME			= do-op
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g
INCLUDES 		= -Iincludes
SRCS_DIR		= srcs
SRCS			= srcs/main.c srcs/operators.c srcs/ft_putnbr.c srcs/ft_atoi.c
OBJS_DIR		= $(SRCS_DIR)
OBJS			= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
RM				= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
