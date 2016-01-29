/*
** invers.c for INVERS in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 27 00:01:54 2016 bougon_p
** Last update Wed Jan 27 07:12:59 2016 bougon_p
*/

#include "paint.h"

void    draw_invpix(t_bunny_position pos, t_bunny_pixelarray *pixarray)
{
  t_color               inv;
  t_color               *color;

  color = (t_color*)pixarray->pixels +
    (pos.x + (pos.y * pixarray->clipable.clip_width));
  inv.argb[0] = 255 - color->argb[0];
  inv.argb[1] = 255 - color->argb[1];
  inv.argb[2] = 255 - color->argb[2];
  tekpixel(pixarray, pos, &inv);
}

void      invers_color(void *_data)
{
  t_data		*data;
  t_bunny_pixelarray	*pixarray;
  t_bunny_position      pos;

  data = _data;
  pixarray = data->crs.calc->pix;
  pos.x = 0;
  while (pos.x < pixarray->clipable.clip_width)
    {
      pos.y = 0;
      while (pos.y < pixarray->clipable.clip_height)
        {
          draw_invpix(pos, pixarray);
          pos.y++;
        }
      pos.x++;
    }
  data->crs.left_click = 0;
}
