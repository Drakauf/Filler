/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 16:12:37 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 16:12:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	int		i;
	long	j;
	char	*str;

	i = ft_intlen(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	j = n;
	if (n < 0)
		j = -j;
	str[i--] = '\0';
	while (i >= 0 && str[i] != '-')
	{
		str[i] = (j % 10) + 48;
		j = j / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
