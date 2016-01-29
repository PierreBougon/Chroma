/*
** font.c for tekpaint in /home/theis_p/gfx_tekpaint/src/tools/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Jan 22 03:05:38 2016 THEIS Paul
** Last update Fri Jan 22 05:24:37 2016 THEIS Paul
*/

#include "paint.h"

void			say(t_bunny_picture		*font,
			    t_bunny_buffer		*pic,
			    const t_bunny_position	*p,
			    const char			*str)
{
  t_bunny_position	pos;
  t_bunny_position	siz;
  int			i;

  siz.x = (5 + 1) * font->scale.x;
  siz.y = 7 * font->scale.y;
  font->clip_y_position = 0;
  font->clip_width = 5;
  font->clip_height = 7;
  pos.x = p->x;
  pos.y = p->y;
  i = 0;
  while (str[i])
    {
      if (str[i] == ' ')
	pos.x += siz.x;
      else
	{
	  font->clip_x_position = str[i] * 5;
	  bunny_blit(pic, font, &pos);
	  pos.x += siz.x;
	}
      ++i;
    }
}
