/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picksim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 21:57:31 by ygaude            #+#    #+#             */
/*   Updated: 2018/06/28 21:58:37 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL_ttf.h>

#include "libft.h"
#include "visu.h"
#include "picksim.h"

t_pin	pingen(t_pin *pins, int index)
{
	int		i;
	int		valid;

	valid = 0;
	while (!valid)
	{
		pins[index].pos = rand() % 100 + 5;
		valid = 1;
		i = 0;
		while (i < index && valid)
			if (pins[index].pos == pins[i++].pos)
				valid = 0;
	}
	pins[index].val = rand() % 100;
	pins[index].status = FREE;
	pins[index].type = NORMAL;
	return (pins[index]);
}

t_lock	lockgen(int size, int secured)
{
	t_lock	lock;
	int		i;
	int		j;

	lock.size = size;
	secured = 0;
	i = -1;
	while (++i < size)
		lock.pins[i] = pingen(lock.pins, i);
	i = 0;
	while (i++ < secured)
	{
		while (lock.pins[(j = rand() % size)].type == SERRATED)
			;
		lock.pins[j].type = SERRATED;
	}
	return (lock);
}

void	debuglock(t_lock lock)
{
	t_pin	pin;
	char	**status;
	int		i;

	i = 0;
	status = (char *[6]){(char *)"FREE", (char *)"SOLVED", (char *)"FAKE"};
	while (i < lock.size)
	{
		pin = lock.pins[i];
		printf("Pin %d:\npos    = %8d\nval    = %8d\nstatus = %8s\ntype   = %8s\n\n",
				i++, pin.pos, pin.val, status[pin.status],
				(pin.type == NORMAL) ? "NORMAL" : "SERRATED");
	}
}

void	debugpick(t_pick pick)
{
	printf("Pick:\ndepth  = %8d\nangle  = %8d\npush   = %8d\n\n",
			pick.depth, pick.angle, pick.push);
}


void	debugenv(t_gamenv genv)
{
	debuglock(genv.lock);
	debugpick(genv.pick);
}

void	debugui(t_gamenv genv)
{
	char		str[17];
	SDL_Rect	rect;
	SDL_Texture	*tex;
	t_winenv	*wenv;

	wenv = getsdlenv();
	rect = (SDL_Rect){.x = 50, .y = 50};
	SDL_SetRenderTarget(wenv->render, wenv->wintex.t);
	SDL_RenderClear(wenv->render);
	sprintf(str, "Pick:");
	tex = strtotex(str, (SDL_Color){255, 255, 255, 255}, 0);
	SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(wenv->render, tex, NULL, &rect);
	SDL_DestroyTexture(tex);
	rect.y += rect.h;
	sprintf(str, "depth = %3d", genv.pick.depth);
	tex = strtotex(str, (SDL_Color){255, 255, 255, 255}, 0);
	SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(wenv->render, tex, NULL, &rect);
	SDL_DestroyTexture(tex);
	rect.y += rect.h;
	sprintf(str, "angle = %3d", genv.pick.angle);
	tex = strtotex(str, (SDL_Color){255, 255, 255, 255}, 0);
	SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(wenv->render, tex, NULL, &rect);
	SDL_DestroyTexture(tex);
	rect.y += rect.h;
	sprintf(str, "push  = %3d", genv.pick.push);
	tex = strtotex(str, (SDL_Color){255, 255, 255, 255}, 0);
	SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(wenv->render, tex, NULL, &rect);
	SDL_DestroyTexture(tex);
}

int		main(void)
{
	t_gamenv	genv;

	srand(time(NULL));
	genv.lock = lockgen(3, 0);
	genv.pick = (t_pick){0, 0, 0};
	visu_init();
	debugenv(genv);
	while (!quitvisu())
	{
		events(&genv.pick);
		debugui(genv);
		visu_update();
	}
	return (0);
}
