/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 09:26:30 by liperman          #+#    #+#             */
/*   Updated: 2022/06/04 11:12:09 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	len_dst;
	size_t	len_src;
	size_t	i;
	size_t	result;

	s = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(s);
	i = 0;
	result = 0;
	if (size > len_dst)
		result = (len_src + len_dst);
	else
		result = len_src + size;
	while (s[i] && (size > len_dst + 1))
	{
		dst[len_dst] = s[i];
		len_dst ++;
		i++;
	}
	dst[len_dst] = '\0';
	return (result);
}
