# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 20:16:17 by hlabouit          #+#    #+#              #
#    Updated: 2023/05/17 20:58:45 by hlabouit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	so_long
SRCS =	parsing.c parsing_2.c valid_path.c display_errors.c \
		useful_functions.c ink_map.c move_player.c so_long.c \
		$(addprefix libft/, ft_putstr_fd.c ft_putnbr_fd.c ft_split.c \
		ft_strjoin.c ft_strlen.c ft_strlcpy.c ft_strdup.c)
		
OBJS = $(SRCS:.c=.o)
CC =  cc
CFLAGS = -Werror -Wall -Wextra

all: $(NAME) libft/libft.a

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

libft/libft.a:
	@$(MAKE) -C libft

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re