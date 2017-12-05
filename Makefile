# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/05 18:54:15 by htaillef     #+#   ##    ##    #+#        #
#    Updated: 2017/12/05 18:54:17 by htaillef    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/ft_printf.c

HEADERS = ./includes

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all