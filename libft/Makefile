# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 02:20:50 by hlabouit          #+#    #+#              #
#    Updated: 2023/05/17 20:58:07 by hlabouit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libft.a
SRCS =  ft_putstr_fd.c ft_putnbr_fd.c ft_split.c \
		ft_strjoin.c ft_strlen.c ft_strlcpy.c ft_strdup.c \

OBJS = $(SRCS:.c=.o)
CC =  cc
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re