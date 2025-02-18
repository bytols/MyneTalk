/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:14:19 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/01 00:13:37 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putstr_fd(char *c, int fd, int *count)
{
	int	i;

	i = 0;
	if (c == NULL)
	{
		write(fd, "(null)", 6);
		*count += 6;
		return ;
	}
	while (c[i] != '\0')
	{
		write (fd, &c[i], 1);
		*count += 1;
		i++;
	}
}
