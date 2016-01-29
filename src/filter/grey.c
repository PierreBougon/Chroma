/*
** shade_of_grey.c for SHADE OF GREY in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 20 03:21:35 2016 bougon_p
** Last update Tue Jan 26 22:13:23 2016 bougon_p
*/

#include "paint.h"

void	draw_pix(t_bunny_position pos,
		 t_bunny_pixelarray *pix, t_bunny_pixelarray *pixarray)
{
  t_color		grey;
  t_color		*color;

  color = (t_color*)pixarray->pixels +
    (pos.x + (pos.y * pixarray->clipable.clip_width));
  grey.argb[0] = (color->argb[0] + color->argb[1] + color->argb[2]) / 3;
  grey.argb[1] = (color->argb[0] + color->argb[1] + color->argb[2]) / 3;
  grey.argb[2] = (color->argb[0] + color->argb[1] + color->argb[2]) / 3;
  grey.argb[3] = 255;
  tekpixel(pix, pos, &grey);
}

t_bunny_pixelarray	*shade_of_grey(t_bunny_pixelarray *pixarray)
{
  t_bunny_position	pos;
  t_bunny_pixelarray	*pix;

  pos.x = 0;
  pix = bunny_new_pixelarray(pixarray->clipable.clip_width,
			     pixarray->clipable.clip_height);
  while (pos.x < pixarray->clipable.clip_width)
    {
      pos.y = 0;
      while (pos.y < pixarray->clipable.clip_height)
	{
	  draw_pix(pos, pix, pixarray);
	  pos.y++;
	}
      pos.x++;
    }
  return (pix);
}
