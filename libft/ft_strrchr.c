/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:54:03 by liperman          #+#    #+#             */
/*   Updated: 2022/06/23 13:48:19 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		strlen;
	char	*result;

	strlen = (int)ft_strlen(s);
	result = (char *)s + strlen;
	while (strlen-- >= 0)
	{
		if (*result == (char)c)
		{
			return (result);
		}
		result --;
	}
	return (NULL);
}
