/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:40:18 by abba          #+#    #+#                 */
/*   Updated: 2021/12/14 14:40:19 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_copy;

	i = 0;
	s_copy = (unsigned char *)s;
	while (n > i)
	{
		if (s_copy[i] == (unsigned char)c)
		{
			return (s_copy + i);
		}
		i++;
	}
	return (0);
}
