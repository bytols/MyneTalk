/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:54:34 by erocha-l          #+#    #+#             */
/*   Updated: 2025/01/31 19:54:34 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK.H

# define MINITALK.H
# include <unistd.h>
# include <signals.h>
#include <>

int			ft_printf(const char *format, ...)
void		ft_putb(unsigned int n, int fd, char *base, int *count)
void		ft_putchar_fd(char c, int fd, int *count)
void		ft_putnbr_fd(int n, int fd, int *count)
static void ft_putnbr_ptr_fd(unsigned long n, int fd, char *base, int *count)
void		ft_putstr_fd(char *c, int fd, int *count)
void		ft_putunbr_fd(unsigned int n, int fd, int *count)
int			ft_atoi(const char *nptr)


#endif