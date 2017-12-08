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

LIBFT_SRCS = 	srcs/libft/ft_printf.c		\
	   			srcs/libft/ft_putchar_fd.c	\
				srcs/libft/ft_putchar.c		\
				srcs/libft/ft_putstr_fd.c	\
				srcs/libft/ft_putstr.c		\
				srcs/libft/ft_putnbr_fd.c	\
				srcs/libft/ft_putnbr.c		\
				srcs/libft/ft_isdigit.c		\
				srcs/libft/ft_atoi.c		\
				srcs/libft/ft_strdup.c		\
				srcs/libft/ft_strcpy.c		\
				srcs/libft/ft_strsub.c		\
				srcs/libft/ft_strlen.c		\
				srcs/libft/ft_strcmp.c

PRINTF_SRCS = 	srcs/display.c				\
				srcs/struct_manager.c		\
				srcs/str_manip.c			\
				srcs/extractor.c			\
		
HEADERS = ./includes

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

%.o : %.c
	@gcc $(FLAGS) -I $(HEADERS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(LIBFT_OBJS) $(PRINTF_OBJS)
	@ar -rcs $(NAME) $(LIBFT_OBJS) $(PRINTF_OBJS)

clean :
	@rm -rf $(LIBFT_OBJS) $(PRINTF_OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all