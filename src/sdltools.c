/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdltools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 21:06:32 by ygaude            #+#    #+#             */
/*   Updated: 2018/06/28 08:23:34 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL_ttf.h>
#include "libft.h"

#include "visu.h"

t_winenv		*getsdlenv(void)
{
	static t_winenv		*winenv = NULL;

	if (!winenv)
		if ((winenv = (t_winenv *)ft_memalloc(sizeof(t_winenv))))
			winenv->quit = 0;
	return (winenv);
}

void			setcolor(SDL_Color color, unsigned char alpha)
{
	t_winenv *env;

	env = getsdlenv();
	SDL_SetRenderDrawColor(env->render, color.r, color.g, color.b, alpha);
}

SDL_Texture		*getnewtex(int access, int w, int h)
{
	SDL_Texture		*tex;
	t_winenv		*env;

	env = getsdlenv();
	tex = SDL_CreateTexture(env->render, env->dispmode.format, access, w, h);
	if (!tex)
		panic("Failed creating texture", SDL_GetError());
	return (tex);
}

void			cleartex(SDL_Texture *tex, SDL_Color col)
{
	t_winenv	*env;

	env = getsdlenv();
	SDL_SetRenderDrawColor(env->render, col.r, col.g, col.b, col.a);
	SDL_SetRenderTarget(env->render, tex);
	SDL_RenderClear(env->render);
}

SDL_Texture		*strtotex(char *str, SDL_Color color, int id)
{
	SDL_Texture		*tex;
	SDL_Surface		*surf;
	t_winenv		*env;

	env = getsdlenv();
	surf = TTF_RenderText_Blended(env->font[id], str, color);
	if (!surf)
		panic("Failed creating text surface", SDL_GetError());
	tex = SDL_CreateTextureFromSurface(env->render, surf);
	if (!tex)
		panic("Failed converting surface to texture", SDL_GetError());
	SDL_FreeSurface(surf);
	return (tex);
}
