/*
** tekpixel.c for PAINT in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Jan  4 19:22:40 2016 bougon_p
** Last update Tue Jan 26 21:44:53 2016 Clémenceau Cedric
*/

#include "paint.h"

void		tekpixel(t_bunny_pixelarray *pix, t_bunny_position pos,
			 t_color *color)
{
  t_color       *col;

  col = (t_color*) pix->pixels +
    (pos.x + (pos.y * pix->clipable.clip_width));
  col->full = color[0].full;
}
