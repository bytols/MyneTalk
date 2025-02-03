/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:54:34 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/03 14:49:03 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct letra 
{
    char letra;
    int size;
} letter ; 

int			ft_printf(const char *format, ...);
void		ft_putb(unsigned int n, int fd, char *base, int *count);
void		ft_putchar_fd(char c, int fd, int *count);
void		ft_putnbr_fd(int n, int fd, int *count);
void		ft_putstr_fd(char *c, int fd, int *count);
void		ft_putunbr_fd(unsigned int n, int fd, int *count);
void	convert_ptr(void *ptr, int *count);
int			ft_atoi(const char *nptr);

#endif