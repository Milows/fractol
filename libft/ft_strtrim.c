/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:48:03 by micabrer          #+#    #+#             */
/*   Updated: 2023/05/13 14:00:15 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Elimina todos los caracteres de la string ’set’ desde el principio y desde 
el final de ’s1’, hasta encontrar un caracter no perteneciente a ’set’*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start_i;
	size_t	end_i;
	size_t	result_len;

	if (!s1 || !set)
		return (NULL);
	start_i = 0;
	while ((s1[start_i]) && ft_strchr(set, s1[start_i]))
		start_i++;
	end_i = ft_strlen(s1);
	while (end_i > start_i && ft_strchr(set, s1[end_i - 1]))
		end_i--;
	result_len = end_i - start_i;
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start_i, result_len +1);
	return (result);
}
