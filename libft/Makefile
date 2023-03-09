# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 13:53:50 by mbertin           #+#    #+#              #
#    Updated: 2023/03/09 11:44:39 by mbertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH	=	src/
D_OBJ		=	obj/
HEADER		=	includes/libft.h
SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_split.c  \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strrchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strmapi.c \
		ft_strnstr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_dbl_ptr_len.c \
		ft_dbl_ptr_copy.c \
		ft_dbl_ptr_free.c \

OBJS = $(patsubst $(D_SRC)%.c,$(D_OBJ)%.o,$(SRCS))

NAME = libft.a

AR = ar rcs

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: $(D_OBJ) ${OBJS}
	@${AR} ${NAME} ${OBJS}

$(D_OBJ):
	@mkdir -p $(D_OBJ)

$(OBJS): $(D_OBJ)%.o : $(SRCS_PATH)%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@${RM} ${D_OBJ}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re