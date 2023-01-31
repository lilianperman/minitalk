/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liperman <liperman@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:50:00 by liperman          #+#    #+#             */
/*   Updated: 2022/06/16 18:08:53 by liperman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	nbrlen(int n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void	write_nbr(long int nbr, char *str, int *i)
{
	if (nbr > 9)
	{
		write_nbr(nbr / 10, str, i);
		write_nbr(nbr % 10, str, i);
	}
	else
	{
		str[*i] = nbr + 48;
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nbr;

	i = 0;
	nbr = n;
	if (n <= 0)
		str = malloc(sizeof(char) * nbrlen(nbr) + 2);
	else
		str = malloc(sizeof(char) * nbrlen(nbr) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		nbr = nbr * -1;
		i ++;
	}
	write_nbr(nbr, str, &i);
	str[i] = '\0';
	return (str);
}
