/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:05:45 by liperman          #+#    #+#             */
/*   Updated: 2022/06/05 12:12:18 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

		str = (unsigned char *)s;
		i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			return ((void *) &str[i]);
		}
		i++;
	}
	return (NULL);
}
