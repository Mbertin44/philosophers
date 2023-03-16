#------------------------------------------------------------------------------#
#								   GENERAL									   #
#------------------------------------------------------------------------------#
NAME = philo
NAME_BONUS = philo_bonus

CC = gcc
#CC = gcc-11
CFLAGS = -g -Wall -Werror -Wextra
#CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf

#LSAN_OPTIONS=detect_leaks=1 ./cub3D

#------------------------------------------------------------------------------#
#								   LIBRARIES								   #
#------------------------------------------------------------------------------#
D_LIBFT = libft/
LIBFT = libft/libft.a
D_LIBFTHEAD = libft/includes/libft.h

#------------------------------------------------------------------------------#
#									SOURCES									   #
#------------------------------------------------------------------------------#
HEADER = includes/philo.h
D_SRC = src/
D_OBJ = obj/
OBJS = $(patsubst $(D_SRC)%.c,$(D_OBJ)%.o,$(SRCS))
SRCS =	src/philo.c \
		src/parsing.c \
		src/utils.c \
		src/init.c \
		src/get_time.c \
		src/routine.c \

#------------------------------------------------------------------------------#
#									 RULES									   #
#------------------------------------------------------------------------------#

all:	 $(NAME)

$(NAME):	$(D_OBJ) $(LIBFT) $(OBJS)
# MacOS 42
	@$(CC) $(CFLAGS) -pthread $(LIBFT) $(OBJS) -o $@

$(LIBFT):	$(D_LIBFTHEAD)
	@$(MAKE) -C $(D_LIBFT)

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
