/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:53:19 by ygaude            #+#    #+#             */
/*   Updated: 2016/11/26 15:43:05 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
