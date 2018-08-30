/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 16:12:40 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 16:12:40 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char *)&haystack[i]);
	while (needle[j] != '\0')
		j++;
	while (haystack[i] != '\0')
	{
		k = 0;
		while (haystack[i] == needle[k] && haystack[i] != '\0')
		{
			i++;
			k++;
		}
		if (k == j)
			return ((char *)&haystack[i - k]);
		i = i - k + 1;
	}
	return (NULL);
}
