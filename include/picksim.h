/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picksim.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 05:30:06 by ygaude            #+#    #+#             */
/*   Updated: 2018/06/29 10:37:39 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PICKSIM_H
# define PICKSIM_H

typedef enum	e_type
{
	NORMAL,
	SERRATED
}				t_type;

typedef enum	e_status
{
	FREE,
	SOLVED,
	FAKE
}				t_status;

typedef struct	s_pin
{
	int			pos;
	int			val;
	t_status	status;
	t_type		type;
}				t_pin;

typedef struct	s_lock
{
	t_pin		pins[8];
	int			prio[8];
	int			solved;
	int			size;
}				t_lock;

typedef struct	s_pick
{
	int			depth;
	int			angle;
	int			push;
	int			holding;
}				t_pick;

typedef struct	s_gamenv
{
	t_lock		lock;
	t_pick		pick;
}				t_gamenv;

#endif
