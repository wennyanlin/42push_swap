/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:22:19 by wlin              #+#    #+#             */
/*   Updated: 2023/09/25 22:37:07 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#define UNUSED(x) (void)(x)

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s_dup;

	if (!s)
		return (NULL);
	s_dup = ft_strdup(s);
	if (!s_dup)
		return (NULL);
	i = 0;
	while (s_dup[i])
	{
		s_dup[i] = f(i, s_dup[i]);
		i++;
	}
	return (s_dup);
}
/*
char	transform_char(unsigned int i, char c)
{
	if (ft_isalpha(c) == 1)
		i = 32;
	else
		i = 0;
	return (c + i); 
}

int	main ()
{
	char	*s = "GOOD NIGHT WEN!";
	char *result;

    result = ft_strmapi(s, transform_char);
	printf("%s", s);
	printf("%s", result);
	return (0);
}*/

/*
questions:
1. why we use *c pointer at line 39?
2. why when we call the function with the parameter 
function adding a & in line 47?*/
