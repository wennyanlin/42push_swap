/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42barcelona.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:32:55 by wlin              #+#    #+#             */
/*   Updated: 2023/09/09 15:33:27 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
	{
		return (c -= 32);
	}
	else
	{
		return (c);
	}
}

/* int	main(void)
{
	int c = 83;

	printf("%d", ft_toupper(c));
} */
