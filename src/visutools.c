/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visutools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 09:03:43 by ygaude            #+#    #+#             */
/*   Updated: 2018/06/28 22:58:26 by ygaude           ###   ########.fr       */
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

void				visu_update(void)
{
	t_winenv *env;

	env = getsdlenv();
	SDL_SetRenderTarget(env->render, env->wintex.t);
	//
	SDL_SetRenderTarget(env->render, NULL);
	SDL_RenderCopy(env->render, env->wintex.t, NULL, NULL);
	SDL_RenderPresent(env->render);
	SDL_SetRenderDrawColor(env->render, 0, 0, 0, 255);
	SDL_RenderClear(env->render);
	SDL_SetRenderTarget(env->render, env->wintex.t);
	SDL_RenderClear(env->render);
}

int					quitvisu(void)
{
	t_winenv *env;

	env = getsdlenv();
	if (!env || env->quit || SDL_QuitRequested())
	{
		TTF_Quit();
		SDL_Quit();
		return (1);
	}
	return (0);
}
