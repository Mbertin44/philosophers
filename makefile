#------------------------------------------------------------------------------#
#					GENERAL				       #
#------------------------------------------------------------------------------#
NAME = philo
NAME_BONUS = philo_bonus

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
# CFLAGS = -g -Wall -Wextra -Werror -fsanitize=thread
RM = rm -rf

#------------------------------------------------------------------------------#
#					SOURCES				       #
#------------------------------------------------------------------------------#
HEADER = includes/philo.h
D_SRC = src/
D_OBJ = obj/
OBJS = $(patsubst $(D_SRC)%.c,$(D_OBJ)%.o,$(SRCS))
SRCS =	src/main.c \
		src/parsing.c \
		src/utils.c \
		src/init_and_stop.c \
		src/get_time_and_check.c \
		src/routine.c \
		src/libft_utils.c \
		src/libft_utils2.c

#------------------------------------------------------------------------------#
#					RULES				       #
#------------------------------------------------------------------------------#

all:	 $(NAME)

$(NAME):	$(D_OBJ) $(OBJS)
	@$(CC) $(CFLAGS) -pthread $(OBJS) -o $@

$(D_OBJ):
	@mkdir -p $(D_OBJ)

$(OBJS): $(D_OBJ)%.o : $(D_SRC)%.c $(HEADER)
		@$(CC) $(CFLAGS) -c $< -o $@


#norm a checker
norm:
	@includes/ norminette
	@src/ norminette

clean:
	@$(RM) $(D_OBJ)

fclean:	clean
	@$(RM) $(NAME) $(NAME_BONUS)

lclean: fclean
	@$(call lcleaning)
	@$(MAKE) -s --no-print-directory -C $(D_LIBFT) fclean

re:	fclean all

.PHONY: all clean fclean lclean re
