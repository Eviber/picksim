/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 21:06:09 by ygaude            #+#    #+#             */
/*   Updated: 2018/07/03 21:41:23 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "picksim.h"

void		movelock(t_gamenv *genv)
{
	int		i;

	i = 0;
	while (i < genv->lock.size && genv->lock.pins[genv->lock.prio[i]].status == SOLVED)
		i++;
	if (i < genv->lock.size && genv->lock.pins[genv->lock.prio[i]].pos < genv->pick.angle)
		genv->lock.angle = genv->lock.pins[genv->lock.prio[i]].pos;
	else if (genv->pick.angle < 1000)
		genv->lock.angle = genv->pick.angle;
	else
		genv->lock.angle = 1000;
}

void		movepins(t_gamenv *genv)
{
	int		i;

	i = 0;
	while (i < genv->lock.size)
	{
		if (genv->lock.pins[i].pos > genv->pick.angle && genv->lock.pins[i].status == SOLVED)
			genv->lock.pins[i].status = FREE;
		else if (genv->lock.angle == genv->lock.pins[i].pos && genv->lock.pins[i].pos + 25 > genv->pick.angle && genv->pick.push == genv->lock.pins[i].val)
			genv->lock.pins[i].status = SOLVED;
		i++;
	}
}

void		pick(t_lock lock, t_pick *pick)
{
	SDL_Point	m;

	if (SDL_GetRelativeMouseState(&m.x, &m.y) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		pick->push += m.y;
		if (pick->push > 100 || pick->push < 0)
			pick->push = (pick->push > 0) ? 100 : 0;
	}
	else
	{
		pick->push = 0;
		pick->depth -= m.y;
		if (pick->depth > 100 || pick->depth < 0)
			pick->depth = (pick->depth > 0) ? 100 : 0;
	}
	if (!pick->holding)
	{
		pick->angle -= m.x;
		if (pick->angle > lock.angle + 100 || pick->angle < 0)
			pick->angle = (pick->angle > 0) ? lock.angle + 100 : 0;
	}
}

void		events(t_gamenv *genv)
{
	Uint8	*keys;

	keys = SDL_GetKeyboardState(NULL);
	genv->pick.holding = keys[SDL_SCANCODE_SPACE];
	pick(genv->lock, &genv->pick);
	movepins(genv);
	movelock(genv);
}
