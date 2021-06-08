/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:29:58 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/08 10:03:24 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if ((char) c == s[i])
			return ((char *) &s[i]);
	}
	if (!c)
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_strjoin_free_dup(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	ptr = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*ptr));
	if (!ptr)
		return (NULL);
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	j = -1;
	while (s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	if (!s)
		return (0);
	if ((ft_strlen(s) + 1) < len)
		ptr = (char *) malloc((ft_strlen(s) + 1) * sizeof(*ptr));
	else
		ptr = (char *) malloc((len + 1) * sizeof(*ptr));
	if (!ptr)
		return (NULL);
	if (start > ft_strlen(s))
	{
		*ptr = 0;
		return (ptr);
	}
	i = 0;
	while (s[i] && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = -1;
	ptr = malloc((1 + ft_strlen(s1)) * sizeof(*ptr));
	if (!ptr)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	ptr[i] = '\0';
	return (ptr);
}
