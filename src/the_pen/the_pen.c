/*
** the_pen.c for THE_PEN in /home/bougon_p/rendu/gfx_tekpaint/src
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Jan 23 04:46:24 2016 bougon_p
** Last update Wed Jan 27 07:50:57 2016 bougon_p
*/

#include "paint.h"

void		the_pen(void *_data)
{
  t_data                        *data;
  t_bunny_position              *circle_pos;
  int                           maxx;
  int                           maxy;

  data = _data;
  if ((circle_pos = bunny_malloc(sizeof(t_bunny_position) * 2)) == NULL)
    return ;
  circle_pos[1].x = data->crs.pencil_pos.x - data->crs.calc->pos.x;
  circle_pos[1].y = data->crs.pencil_pos.y - data->crs.calc->pos.y;
  maxx = data->sup->pos.x + data->sup->pixarray->clipable.clip_width;
  maxy = data->sup->pos.y + data->sup->pixarray->clipable.clip_height;
  if ((data->crs.pencil_pos.x > data->crs.calc->pos.x &&
       data->crs.pencil_pos.x < maxx)
      && (data->crs.pencil_pos.y > data->crs.calc->pos.y &&
          data->crs.pencil_pos.y < maxy))
    rond(circle_pos, data->tools.size, data);
  bunny_free(circle_pos);
  return ;
}
