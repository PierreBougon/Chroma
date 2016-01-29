/*
** select.c for select in /home/goubea_t/graph/gfx_tekpaint
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Wed Jan 20 01:40:20 2016 Tristan goubeau
** Last update Tue Jan 26 22:01:46 2016 Tristan goubeau
*/

#include "paint.h"

void			my_set_select(t_bunny_pixelarray *pix, t_data *data)
{
  int                   i;
  int                   j;
  t_bunny_position      pose;
  t_color		col;

  col.full = 0xFF0000;
  i = data->sel.previous_pos.x;
  j = data->sel.previous_pos.y;
  while (j < data->sel.previous_pos.y + ABS(data->sel.next_pos.x -
					  data->sel.previous_pos.x))
    {
      while (i < data->sel.previous_pos.x + ABS(data->sel.next_pos.y -
					  data->sel.previous_pos.y))
        {
          pose.x = i;
          pose.y = j;
          tekpixel(pix, pose, &col);
          i++;
        }
      i = data->sel.previous_pos.x;
      j++;
    }
}


void	my_select(t_bunny_pixelarray *pix, t_data *data)
{
  my_set_select(pix, data);
}
