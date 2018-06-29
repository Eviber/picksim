/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 21:06:09 by ygaude            #+#    #+#             */
/*   Updated: 2018/06/29 08:13:40 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "picksim.h"

void		mouse(t_pick *pick)
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
		if (pick->angle > 1000 || pick->angle < 0)
			pick->angle = (pick->angle > 0) ? 1000 : 0;
	}
}

void		events(t_pick *pick)
{
	Uint8	*keys;

	keys = SDL_GetKeyboardState(NULL);
	pick->holding = keys[SDL_SCANCODE_SPACE];
	mouse(pick);
}
