/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momo <momo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:50:13 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/01 13:41:56 by momo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/libft.h"

char	*ft_strnstr(const char *str, const char *found, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (found[i] == '\0')
		return ((char *)str);
	while (i < n && str[i] != '\0')
	{
		j = 0;
		while (i + j < n && str[i + j] == found[j])
		{
			if (found[j + 1] == '\0')
				return ((char *) str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
