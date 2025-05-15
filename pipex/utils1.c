/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:31:13 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/13 19:05:47 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_substrings(char const *s, char c)
{
	int	count;
	int	len;
	int	i;
	int	old_i;

	i = 0;
	len = ft_strlen(s);
	old_i = 0;
	count = 0;
	while (i < len)
	{
		while (i < len && s[i] == c)
			i++;
		old_i = i;
		while (i < len && s[i] != c)
			i++;
		if (i > old_i)
			count++;
	}
	return (count);
}

static char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static void	split_into_substrings(char **str, char const *s, char c)
{
	int	string_index;
	int	start;
	int	i;
	int	len;

	i = 0;
	start = 0;
	string_index = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		while (i < len && s[i] == c)
			i++;
		start = i;
		while (i < len && s[i] != c)
			i++;
		if (i > start)
		{
			str[string_index] = malloc(i - start + 1);
			ft_strncpy(str[string_index], &s[start], i - start);
			str[string_index][i - start] = '\0';
			string_index++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = count_substrings(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = NULL;
	i = count;
	split_into_substrings(str, s, c);
	while (i > 0)
	{
		if (str[i - 1] == NULL)
		{
			free(str[i - 1]);
			free(str);
			return (NULL);
		}
		i--;
	}
	return (str);
}

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}
