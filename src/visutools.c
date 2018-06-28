/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visutools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 09:03:43 by ygaude            #+#    #+#             */
/*   Updated: 2018/06/28 08:34:14 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <SDL_ttf.h>

#include "libft.h"
#include "visu.h"

void				panic(const char *str, const char *str2)
{
	ft_dprintf(2, "%s: %s\n", str, str2);
	exit(-1);
}

void				visu_update(t_winenv *env)
{
	SDL_SetRenderTarget(env->render, env->wintex.t);
	//
	SDL_SetRenderTarget(env->render, NULL);
	SDL_RenderCopy(env->render, env->wintex.t, NULL, NULL);
}

int					quitvisu(t_winenv *env)
{
	if (!env || env->quit || SDL_QuitRequested())
	{
		SDL_Quit();
		return (0);
	}
	return (1);
}
