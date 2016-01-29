/*
** get_color.c for get_color in /home/goubea_t/graph/gfx_tekpaint
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Mon Jan 25 15:52:48 2016 Tristan goubeau
** Last update Tue Jan 26 20:37:22 2016 bougon_p
*/

#include "paint.h"

t_color		*get_color(t_data *data, int x, int y)
{
  t_color       *color;

  color = (t_color *)data->sup->pixarray->pixels + x +
    (y * data->sup->pixarray->clipable.clip_width);
  return (color);
}
