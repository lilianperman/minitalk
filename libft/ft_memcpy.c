/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:48:05 by liperman          #+#    #+#             */
/*   Updated: 2022/05/28 17:14:46 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	position;

	if (!dst && !src)
		return (0);
	position = 0;
	while (position < n)
	{
		((unsigned char *)dst)[position] = ((unsigned char *)src)[position];
		position++;
	}
	return (dst);
}
