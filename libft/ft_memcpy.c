/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:40:28 by abba          #+#    #+#                 */
/*   Updated: 2021/12/14 14:40:29 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d_copy;
	unsigned char		*s_copy;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	d_copy = (unsigned char *)dst;
	s_copy = (unsigned char *)src;
	while (n > i)
	{
		d_copy[i] = s_copy[i];
		i++;
	}
	return (dst);
}
