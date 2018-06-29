/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 22:15:40 by ygaude            #+#    #+#             */
/*   Updated: 2018/06/29 07:42:24 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include "picksim.h"
#include "visu.h"

void	visualize(t_gamenv genv)
{
	SDL_Rect	rect;
	t_winenv	*wenv;

	wenv = getsdlenv();
	SDL_SetRenderTarget(wenv->render, wenv->wintex.t);
	rect.w = 50;
	rect.h = wenv->dispmode.h;
	rect.x = wenv->dispmode.w / 4 - rect.w / 2;
	rect.y = wenv->dispmode.h - (genv.pick.depth * wenv->dispmode.h / 100) + genv.pick.push / 2;
	SDL_SetRenderDrawColor(wenv->render, 100, 100, 100, 255);
	SDL_RenderFillRect(wenv->render, &rect);
	rect.w = genv.pick.depth * wenv->dispmode.w / 2 / 100;
	rect.h = 50;
	rect.x = wenv->dispmode.w / 2;
	rect.y = wenv->dispmode.h / 4 + genv.pick.push;
	SDL_SetRenderDrawColor(wenv->render, 100, 100, 100, 255);
	SDL_RenderFillRect(wenv->render, &rect);
	SDL_SetRenderDrawColor(wenv->render, 0, 0, 0, 255);
	if (genv.pick.angle < 1000)
		filledPieRGBA(wenv->render, 1000, 800, 100, 90, 90 + genv.pick.angle * 360 / 1000, 100, 110, 120, 255);
	else
		filledCircleRGBA(wenv->render, 1000, 800, 100, 100, 200, 120, 255);
}
