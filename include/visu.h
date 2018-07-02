/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaude <ygaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 20:22:21 by ygaude            #+#    #+#             */
/*   Updated: 2018/07/02 18:14:50 by ygaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <SDL.h>
# include <SDL_ttf.h>

# include "picksim.h"

# define TEXTARGET SDL_TEXTUREACCESS_TARGET

typedef struct			s_tex
{
	SDL_Rect			r;
	SDL_Texture			*t;
}						t_tex;

typedef struct			s_winenv
{
	SDL_DisplayMode		dispmode;
	t_tex				wintex;
	SDL_Window			*win;
	SDL_Renderer		*render;
	TTF_Font			*font[2];
	Uint32				lastticks;
	Uint32				ticks;
	int					quit;
}						t_winenv;

/*
**	Generic tools
*/
void					panic(const char *str, const char *str2);
t_winenv				*getsdlenv(void);
SDL_Texture				*getnewtex(int access, int w, int h);
void					cleartex(SDL_Texture *tex, SDL_Color col);
SDL_Texture				*strtotex(char *str, SDL_Color color, int id);
void					setcolor(SDL_Color color, unsigned char alpha);

/*
**	Specific tools
*/
void					visu_update(void);
void					events(t_gamenv *genv);
void					visualize(t_gamenv genv);

/*
**	Subfunctions
*/

/*
**	Main functions
*/
void					visu_init(void);
void					visu_finish(void);
int						visu(void);
int						quitvisu(void);

#endif
