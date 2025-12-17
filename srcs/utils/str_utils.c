/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:19:43 by fomanca           #+#    #+#             */
/*   Updated: 2025/12/16 17:24:37 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	str_to_long(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * sign);
}

static int	count_words(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*word_dup(char *s, char c, int *idx)
{
	char	*w;
	int		len;
	int		i;

	len = 0;
	while (s[*idx + len] && s[*idx + len] != c)
		len++;
	w = malloc(len + 1);
	if (!w)
		return (NULL);
	i = 0;
	while (i < len)
		w[i++] = s[(*idx)++];
	w[i] = '\0';
	return (w);
}

static char	**fill_words(char **res, char *s, char c, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < count)
	{
		while (s[i] == c)
			i++;
		res[j] = word_dup(s, c, &i);
		if (!res[j])
		{
			free_tab(res);
			return (NULL);
		}
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**split_input(char *s, char c)
{
	char	**res;
	int		count;

	count = count_words(s, c);
	if (!count)
		return (NULL);
	res = malloc(sizeof(char *) * (count + 2));
	if (!res)
		return (NULL);
	return (fill_words(res, s, c, count));
}
