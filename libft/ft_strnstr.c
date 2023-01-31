/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:51:43 by liperman          #+#    #+#             */
/*   Updated: 2022/06/14 19:54:23 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bigStr, const char *littleStr, size_t len)
{
	size_t	len_littlestr;

	len_littlestr = ft_strlen(littleStr);
	if (*littleStr == '\0')
	{
		return ((char *)bigStr);
	}
	while (*bigStr != '\0' && len >= len_littlestr)
	{
		if (*bigStr == *littleStr
			&& ft_strncmp(bigStr, littleStr, len_littlestr) == 0)
		{
			return ((char *)bigStr);
		}
		bigStr++;
		len--;
	}
	return (NULL);
}
