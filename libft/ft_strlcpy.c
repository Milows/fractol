/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:01:25 by micabrer          #+#    #+#             */
/*   Updated: 2023/05/10 11:09:55 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*copia una cadena de caracteres de origen en una de destino 
se segura que 'dst' sea nul-terminada */
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	while (*src && (i + 1 < dst_size))
	{
		*dst++ = *src++;
		i++;
	}
	if (dst_size > 0)
	{
		*dst = '\0';
	}
	while (*src++)
		i++;
	return (i);
}
