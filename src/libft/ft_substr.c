/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:06:38 by wlin              #+#    #+#             */
/*   Updated: 2023/09/21 13:43:24 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*sub_s;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	sub_len = len;
	if (start >= s_len)
	{
		sub_s = (char *)malloc(sizeof(char));
		if (sub_s == NULL)
			return (NULL);
		*sub_s = '\0';
		return (sub_s);
	}
	if ((start + sub_len) > s_len)
		sub_len = s_len - start;
	sub_s = (char *)malloc(sub_len + 1);
	if (!sub_s)
		return (NULL);
	ft_strlcpy(sub_s, s + start, sub_len + 1);
	return (sub_s);
}
/*
int	main()
{
	char			*s = "holaquetal";
	unsigned int	start = 0;
	size_t			len = 10;

	printf("%s", ft_substr(s, start, len));
	return (0);
}*/
