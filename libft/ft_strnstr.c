/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:42:10 by abba          #+#    #+#                 */
/*   Updated: 2021/12/14 14:42:11 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while ((char)*haystack && k <= (len - ft_strlen(needle)))
	{
		if ((char)needle[i] == (char)haystack[i])
		{
			i++;
			if (i == ft_strlen(needle))
				return ((char *)haystack);
		}
		else
		{
			haystack++;
			i = 0;
			k++;
		}
	}
	return (NULL);
}
