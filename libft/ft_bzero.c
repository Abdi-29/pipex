/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:39:30 by abba          #+#    #+#                 */
/*   Updated: 2021/12/14 14:39:31 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_copy;

	i = 0;
	s_copy = (unsigned char *)s;
	while (n > i)
	{
		s_copy[i] = '\0';
		i++;
	}
}
