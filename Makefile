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

SRCS = 	srcs/ft_printf.c		\
	   	srcs/ft_putchar_fd.c	\
		srcs/ft_putchar.c		\
		srcs/ft_putstr_fd.c		\
		srcs/ft_putstr.c		\
		srcs/ft_putnbr_fd.c		\
		srcs/ft_putnbr.c		\
		srcs/display.c			\
		srcs/struct_manager.c	\
		srcs/str_manip.c		\
		srcs/ft_strsub.c		\
		srcs/ft_strlen.c		\
		srcs/extractor.c		\
		srcs/ft_isdigit.c		\
		srcs/ft_atoi.c			\
		srcs/ft_strdup.c		\
		srcs/ft_strcpy.c

HEADERS = ./includes

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

%.o : %.c
	@gcc $(FLAGS) -I $(HEADERS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all