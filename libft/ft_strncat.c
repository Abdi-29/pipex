/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:42:00 by abba          #+#    #+#                 */
/*   Updated: 2021/12/14 14:42:01 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dst, const char *src)
{
	int	j;
	int	i;

	j = 0;
	i = ft_strlen(dst);
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
