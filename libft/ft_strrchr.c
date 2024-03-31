/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:27:13 by micabrer          #+#    #+#             */
/*   Updated: 2023/05/08 19:27:14 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*busca la ultima ocurrencia del caracter c en "s"*/
char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0 && s[len] != (char)c)
	{
		len--;
	}
	if (s[len] == (char)c)
	{
		return ((char *)& s[len]);
	}
	return (NULL);
}
