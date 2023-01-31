/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:35:27 by liperman          #+#    #+#             */
/*   Updated: 2022/06/23 15:47:28 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*newstr;

	i = 0;
	k = 0;
	if (str == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)str);
	j = ft_strlen(str);
	while (str[i] != '\0' && ft_strchr(set, str[i]) != NULL)
		i++;
	while (j > i && ft_strchr(set, str[j - 1]) != NULL)
		j--;
	newstr = (char *)malloc(sizeof(const char) * (j - i + 1));
	if (newstr == NULL)
		return (NULL);
	while (i < j)
	{
		newstr[k++] = str[i++];
	}
	newstr[k] = '\0';
	return (newstr);
}
