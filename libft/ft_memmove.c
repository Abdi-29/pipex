/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:40:32 by abba          #+#    #+#                 */
/*   Updated: 2021/12/14 14:40:33 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_why(unsigned char *d, unsigned char *s, size_t len)
{
	while (len > 0)
	{
		*d = *s;
		d++;
		s++;
		len--;
	}
	return (d);
}

static void	*ft_why1(unsigned char *d, unsigned char *s, size_t len)
{
	d += len - 1;
	s += len - 1;
	while (len > 0)
	{
		*d = *s;
		d--;
		s--;
		len--;
	}
	return (d);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (dst);
	if (d <= s)
	{
		d = ft_why(d, s, len);
	}
	else
	{
		d = ft_why1(d, s, len);
	}
	return (dst);
}
