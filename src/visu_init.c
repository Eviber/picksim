/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 08:36:55 by ygaude            #+#    #+#             */
/*   Updated: 2018/06/28 21:48:42 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <SDL_ttf.h>

#include "visu.h"

static void			initsdl(t_winenv *env, const char *name, Uint32 flags)
{
	if (!env || SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
		panic("Error while initializing SDL", SDL_GetError());
	if (SDL_GetDesktopDisplayMode(0, &(env->dispmode)))
		panic("SDL_GetDesktopDisplayMode failed", SDL_GetError());
	env->win = SDL_CreateWindow(name,
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				env->dispmode.w, env->dispmode.h, flags);
	if (!env->win)
		panic("Error while creating window", SDL_GetError());
	env->render = SDL_CreateRenderer(env->win, -1, SDL_RENDERER_ACCELERATED);
	if (!env->render)
		panic("Error while creating renderer", SDL_GetError());
	if (TTF_Init() == -1 ||
		!(env->font[0] = TTF_OpenFont("resources/roboto.ttf", 20)) ||
		!(env->font[1] = TTF_OpenFont("resources/impact.ttf", 200)))
		panic("Error while initializing SDL_TTF", TTF_GetError());
	SDL_SetRenderDrawColor(env->render, 9, 11, 16, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(env->render);
}

void				visu_init(void)
{
	t_winenv		*env;
	SDL_DisplayMode	dm;

	env = getsdlenv();
	initsdl(env, "pick sim", 0);
	SDL_GetDesktopDisplayMode(0, &env->dispmode);
	dm = env->dispmode;
	env->wintex.t = getnewtex(TEXTARGET, dm.w, dm.h);
	cleartex(env->wintex.t, (SDL_Color){10, 10, 10, SDL_ALPHA_OPAQUE});
	SDL_SetRelativeMouseMode(SDL_TRUE);
	visu_update();
}
