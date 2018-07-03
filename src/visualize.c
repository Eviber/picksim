/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 22:15:40 by ygaude            #+#    #+#             */
/*   Updated: 2018/07/03 21:53:30 by ygaude           ###   ########.fr       */
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

	rect.w = 10;
	rect.h = wenv->dispmode.h / 4;
	rect.x = wenv->dispmode.w / 4 - rect.w / 2;
	rect.y = wenv->dispmode.h / 2 - (genv.pick.depth * rect.h / 200) + genv.pick.push / 2;
	SDL_SetRenderDrawColor(wenv->render, 100, 100, 100, 255);
	SDL_RenderFillRect(wenv->render, &rect);

	rect.w = wenv->dispmode.w / 3;
	rect.h = 70;
	rect.x = wenv->dispmode.w / 3 + genv.pick.depth * rect.w / 2 / 100;
	rect.y = wenv->dispmode.h / 4 + genv.pick.push;
	SDL_SetRenderDrawColor(wenv->render, 100, 100, 100, 255);
	SDL_RenderFillRect(wenv->render, &rect);
	SDL_SetRenderDrawColor(wenv->render, 0, 0, 0, 255);

	rect.y += 20;
	rect.h -= 20;
	rect.w -= 20;
	SDL_RenderFillRect(wenv->render, &rect);
	SDL_SetRenderDrawColor(wenv->render, 0, 0, 0, 255);

	if (genv.lock.angle < 1000)
	{
		filledPieRGBA(wenv->render, 1000, 800, 100, 90, 90 + genv.pick.angle * 360 / 1001, 200, 110, 120, 255);
		filledPieRGBA(wenv->render, 1000, 800, 100, 90, 90 + genv.lock.angle * 360 / 1000, 100, 110, 120, 255);
	}
	else
		filledCircleRGBA(wenv->render, 1000, 800, 100, 100, 200, 120, 255);
}
