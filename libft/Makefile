# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momo <momo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 13:53:50 by mbertin           #+#    #+#              #
#    Updated: 2023/03/01 13:40:26 by momo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH = src/
SRCS = 	$(SRCS_PATH)ft_atoi.c \
		$(SRCS_PATH)ft_bzero.c \
		$(SRCS_PATH)ft_calloc.c \
		$(SRCS_PATH)ft_isalnum.c \
		$(SRCS_PATH)ft_isalpha.c \
		$(SRCS_PATH)ft_isascii.c \
		$(SRCS_PATH)ft_isdigit.c \
		$(SRCS_PATH)ft_isprint.c \
		$(SRCS_PATH)ft_itoa.c \
		$(SRCS_PATH)ft_memchr.c \
		$(SRCS_PATH)ft_memcmp.c \
		$(SRCS_PATH)ft_memcpy.c \
		$(SRCS_PATH)ft_memmove.c \
		$(SRCS_PATH)ft_memset.c \
		$(SRCS_PATH)ft_split.c  \
		$(SRCS_PATH)ft_strchr.c \
		$(SRCS_PATH)ft_strdup.c \
		$(SRCS_PATH)ft_strjoin.c \
		$(SRCS_PATH)ft_strlen.c \
		$(SRCS_PATH)ft_strncmp.c \
		$(SRCS_PATH)ft_strrchr.c \
		$(SRCS_PATH)ft_strlcat.c \
		$(SRCS_PATH)ft_strlcpy.c \
		$(SRCS_PATH)ft_strmapi.c \
		$(SRCS_PATH)ft_strnstr.c \
		$(SRCS_PATH)ft_strtrim.c \
		$(SRCS_PATH)ft_substr.c \
		$(SRCS_PATH)ft_tolower.c \
		$(SRCS_PATH)ft_toupper.c \
		$(SRCS_PATH)ft_striteri.c \
		$(SRCS_PATH)ft_putchar_fd.c \
		$(SRCS_PATH)ft_putstr_fd.c \
		$(SRCS_PATH)ft_putendl_fd.c \
		$(SRCS_PATH)ft_putnbr_fd.c \

OBJS = ${SRCS:%c=%o}

NAME = libft.a

AR = ar rcs

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re