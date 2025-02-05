# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 11:25:47 by erocha-l          #+#    #+#              #
#    Updated: 2025/02/01 00:31:29 by erocha-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  minitalk.a

FLAGS =-Wall	\
       -Werror  \
       -Wextra  \

CC= cc

C_SOURCE= libft/ft_atoi.c printf/ft_putchar_fd.c printf/ft_printf.c printf/ft_putstr_fd.c printf/ft_putnbr_fd.c printf/ft_putb.c printf/ft_putnbr_ptr_fd.c printf/ft_putunbr_fd.c

H_FILES = minitalk.h 

OBJ_SOURCE= ft_atoi.o ft_putchar_fd.o ft_printf.o ft_putstr_fd.o ft_putnbr_fd.o ft_putb.o ft_putnbr_ptr_fd.o ft_putunbr_fd.o

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SOURCE)
	ar -src $(NAME) $(OBJ_SOURCE)
	$(CC) $(FLAGS) server.c minitalk.a -o server 
	$(CC) $(FLAGS) client.c minitalk.a -o client 


$(OBJ_SOURCE): $(C_SOURCE)
	$(CC) $(FLAGS) -c $(C_SOURCE)
 
re: $(NAME) $(OBJ_SOURCE)
	make fclean
	make all

clean:
	rm -rf $(OBJ_SOURCE)

fclean:
	rm -rf $(NAME)
	rm -rf $(OBJ_SOURCE)

.PHONY: all clean fclean re
