/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lm.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 16:12:38 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 16:12:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_lm(char const *str, int i, char c)
{
	int j;

	j = 0;
	while (str[i] != c && str[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}
