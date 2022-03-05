# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouinia <asouinia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 12:30:34 by asouinia          #+#    #+#              #
#    Updated: 2021/12/13 01:55:05 by asouinia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE		:= ./
NAME		:= libft.a
SRC			:= ft_atoi.c  \
			ft_bzero.c  \
			ft_calloc.c  \
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
			ft_putchar_fd.c  \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_toupper.c \
			ft_tolower.c 
OBJ			:= $(SRC:.c=.o)
SRCB		:= ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c
OBJB		:= $(SRCB:.c=.o)
FLAGS		:= -Wall -Wextra -Werror
.PHONY		:  all clean fclean re


all: $(NAME)

$(NAME): $(OBJ)

%.o:%.c
	@gcc $(FLAGS) -c $< -I $(INCLUDE)
	@ar -rc $(NAME) $@
bonus: $(OBJB)
clean:
	@rm -f $(OBJ) $(OBJB) 
fclean: clean
	@rm -f $(NAME)
re: fclean all