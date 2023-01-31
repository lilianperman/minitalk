/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:35:45 by liperman          #+#    #+#             */
/*   Updated: 2022/06/23 14:26:51 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *text)
{
	char	*copy;

	copy = (char *)malloc(sizeof(char) * ft_strlen(text) + 1);
	if (!copy)
		return (0);
	else
	{
		ft_strlcpy (copy, text, ft_strlen(text) + 1);
		return (copy);
	}
}
