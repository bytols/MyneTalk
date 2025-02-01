# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 11:25:47 by erocha-l          #+#    #+#              #
#    Updated: 2025/01/07 17:22:38 by erocha-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  minitalk.a

FLAGS =-Wall	\
       -Werror  \
       -Wextra  \

CC= cc

C_SOURCE= libft/ft_atoi.c printf/ft_putchar_fd.c printf/ft_printf.c printf/ft_putstr_fd.c printf/ft_putnbr_fd.c printf/ft_putb.c printf/ft_putnbr_ptr_fd.c printf/ft_putunbr_fd.c client.c serve.c

H_FILES = push_swap.h 

OBJ_SOURCE= $(C_SOURCE:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SOURCE)
	ar -src $(NAME) $(OBJ_SOURCE)
	$(CC) $(FLAGS) push_swap.c push_swap.a -o push_swap 

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
