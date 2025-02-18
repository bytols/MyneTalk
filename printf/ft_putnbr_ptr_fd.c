/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:09:35 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/01 00:18:43 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

 void	ft_putnbr_ptr_fd(unsigned long n, int fd, char *base, int *count)
{
	if (n > 15)
	{
		ft_putnbr_ptr_fd ((n / 16), fd, base, count);
		ft_putnbr_ptr_fd ((n % 16), fd, base, count);
	}
	else
	{
		n = base[n];
		write (fd, &n, 1);
		*count += 1;
	}
}

void	convert_ptr(void *ptr, int *count)
{
	unsigned long	num;

	if (ptr == NULL)
	{
		write (1, "(nil)", 5);
		*count += 5;
		return ;
	}
	num = (unsigned long ) ptr;
	write (1, "0", 1);
	write (1, "x", 1);
	*count += 2;
	ft_putnbr_ptr_fd(num, 1, "0123456789abcdef", count);
}
