/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 16:12:40 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 16:12:40 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = c;
	while (s[i] != '\0')
		i++;
	while (i >= 0 && s[i] != c)
	{
		i--;
	}
	if (s[i] == c || c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
