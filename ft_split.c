/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: akerdeka <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 16:42:06 by akerdeka     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 17:44:22 by akerdeka    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char **tab, int i)
{
	while (i > 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (0);
}

static char	*ft_algo(const char *s, char c, char **tab)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (!(word = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_countwords(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	return (j);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = ft_countwords(s, c);
	if (!(tab = malloc(sizeof(char *) * (j + 1))))
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(tab[i] = ft_algo(s, c, tab)))
				return (ft_free(tab, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
