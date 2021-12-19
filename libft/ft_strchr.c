/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 14:41:07 by abba          #+#    #+#                 */
/*   Updated: 2021/12/14 14:41:08 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s_copy;

	i = 0;
	s_copy = (char *)s;
	while (s_copy[i])
	{
		if (s_copy[i] == (char)c)
			return (s_copy + i);
		i++;
	}
	if (c == 0)
		return (s_copy + i);
	return (0);
}
