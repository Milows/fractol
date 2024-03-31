/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:59:10 by micabrer          #+#    #+#             */
/*   Updated: 2023/05/10 23:42:39 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Envía el carácter ’c’ al file descriptor especificado.*/
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
