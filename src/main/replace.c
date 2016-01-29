/*
** replace.c for REPLACE PIXARRAY in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Jan 24 06:23:06 2016 bougon_p
** Last update Wed Jan 27 03:22:37 2016 THEIS Paul
*/

# include "paint.h"

void	replace_draw_area(t_data *data)
{
  if (data->crs.calc->pix != NULL)
    {
      data->crs.calc->pos.x = 78 + (data->pixback->clipable.clip_width / 2
			       - data->sup->pixarray->clipable.clip_width / 2);
      data->crs.calc->pos.y = 2 + (data->pixback->clipable.clip_height / 2
			      - data->sup->pixarray->clipable.clip_height / 2);
    }
}
