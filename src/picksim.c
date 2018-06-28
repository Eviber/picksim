/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picksim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 21:57:31 by ygaude            #+#    #+#             */
/*   Updated: 2018/06/28 10:47:49 by ygaude           ###   ########.fr       */
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

void	debugpin(t_pin pin)
{
	printf("pos = %d\nval = %d\nstatus = ",
			pin.pos, pin.val);
	if (pin.status == FREE)
		printf("FREE\n");
	else
		printf("%s\n", (pin.status == SOLVED) ? "SOLVED" : "FAKE");
	printf("type = %s\n\n", (pin.type == NORMAL) ? "NORMAL" : "SERRATED");
}

void	debuglock(t_lock lock)
{
	int		i;
	
	i = 0;
	while (i < lock.size)
	{
		printf("Pin %d:\n", i);
		debugpin(lock.pins[i++]);
	}
}

void	debugpick(t_pick pick)
{
	printf("Pick:\ndepth = %d\nangle = %d\npush = %d\n\n",
			pick.depth, pick.angle, pick.push);
}


void	debugenv(t_gamenv genv)
{
	debuglock(genv.lock);
	debugpick(genv.pick);
}

int		main(void)
{
	t_gamenv	genv;

	srand(time(NULL));
	genv.lock = lockgen(3, 0);
	genv.pick = (t_pick){0, 0, 0};
	debugenv(genv);
	return (0);
}
