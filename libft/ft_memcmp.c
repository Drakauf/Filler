/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 16:12:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 16:12:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t;
	unsigned char	*s;
	size_t			i;

	i = 0;
	t = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (i < n)
	{
		if (t[i] != s[i])
			return (t[i] - s[i]);
		i++;
	}
	return (0);
}
