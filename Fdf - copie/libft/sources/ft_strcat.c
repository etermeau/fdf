/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:29:08 by etermeau          #+#    #+#             */
/*   Updated: 2014/12/12 21:14:31 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;
	
	j = 0;
	i = 0;
	if (s1)
	{
		while (s1[i])
			i++;
	}
	if (s2)
	{
		while (s2[j])
		{
			s1[i + j] = s2[j];
			j++;
		}
	}
	s1[i + j] = '\0';
	return (s1);
}