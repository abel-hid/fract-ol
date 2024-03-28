# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 22:31:44 by abel-hid          #+#    #+#              #
#    Updated: 2023/01/31 22:31:46 by abel-hid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c\
		mandelbrot.c\
		julia.c\
		utlis.c\
		color.c\
		event.c\
		map.c\
		ft_atof.c\


BSRCS = tricorn.c\
		bonus.c\
		utlis.c\
		color.c\
		event.c\

OBJ = $(SRCS:.c=.o)

BOBJ =  $(BSRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(BOBJ)
	$(CC) $(BOBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
