/*
** tekpixel.c for PAINT in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Jan  4 19:22:40 2016 bougon_p
** Last update Tue Jan 26 07:07:25 2016 THEIS Paul
*/

#include "paint.h"

unsigned int	getpixelcolor(t_bunny_pixelarray *array,
			       t_bunny_position *pos)
{
  t_color       *col;

  if ((pos[0].x <= array->clipable.clip_width && pos[0].x >= 0) &&
      (pos[0].y <= array->clipable.clip_height && pos[0].y) >= 0)
    {
      col = (t_color*)array->pixels + pos[0].x +
        (pos[0].y *array->clipable.clip_width);
      return (col->full);
    }
  return (0);
}

void		ptekpixel(t_bunny_pixelarray *pix, t_bunny_position pos,
			 t_color *color)
{
  t_color       *col;

  if (pos.x >= 0 && pos.x < PAINT_WIDTH && pos.y >= 0 && pos.y < PAINT_HEIGHT)
    {
      col = (t_color*)pix->pixels +
	(pos.x + (pos.y * pix->clipable.clip_width));
      col->full = color[0].full;
    }
}

void		dtekpixel(t_bunny_pixelarray *pix, t_bunny_position pos,
			 t_color *color)
{
  t_color       *col;

  if (pos.x >= 0 && pos.x < pix->clipable.clip_width && pos.y >= 0 &&
      pos.y < pix->clipable.clip_height)
    {
      col = (t_color*)pix->pixels +
	(pos.x + (pos.y * pix->clipable.clip_width));
      col->full = color[0].full;
    }
}

void		tekpixel(t_bunny_pixelarray *pix, t_bunny_position pos,
			 t_color *color)
{
  t_color       *col;

  if (pos.x >= 0 && pos.x < WIN_WIDTH && pos.y >= 0 && pos.y < WIN_HEIGHT)
    {
      col = (t_color*)pix->pixels +
	(pos.x + (pos.y * pix->clipable.clip_width));
      col->full = color[0].full;
    }
}
