/*
** draw_square.c for SQUARE in /home/bougon_p/rendu/gfx_tekpaint/src
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Jan 23 04:42:04 2016 bougon_p
** Last update Wed Jan 27 01:05:53 2016 THEIS Paul
*/

#include "paint.h"

void		square_final(t_data *data)
{
  t_posrec	posrec;

  posrec.color	= data->tools.color;
  posrec.x = data->square.init_pos.x;
  posrec.y = data->square.init_pos.y;
  data->square.sizex = data->square.sizex - data->sup->pos.x;
  data->square.sizey = data->square.sizey - data->sup->pos.y;
  my_setsquare(data->crs.calc->pix, posrec,
	       data->square.sizex, data->square.sizey);
  data->tools.square_act = 0;
}

void		fill_data(t_data *data, t_bunny_position mouse_pos)
{
  data->square.final_pos.x = mouse_pos.x;
  data->square.final_pos.y = mouse_pos.y;
  data->square.sizex = mouse_pos.x - data->square.init_pos.x;
  data->square.sizey = mouse_pos.y - data->square.init_pos.y;
}

t_bunny_position		take_mouse_pos(t_data *data)
{
  const t_bunny_position	*mouse;
  t_bunny_position		mouse_pos;

  if (data->square.pass == 0)
    {
      mouse = bunny_get_mouse_position();
      data->square.init_pos.x = mouse->x;
      data->square.init_pos.y = mouse->y;
    }
  else
    {
      mouse = bunny_get_mouse_position();
      mouse_pos.x = mouse->x;
      mouse_pos.y = mouse->y;
    }
  return (mouse_pos);
}

void				draw_square(void *_data)
{
  t_data			*data;
  t_bunny_position		mouse_pos;
  int				size_x;
  int				size_y;

  data = _data;
  if (data->square.pass != -1)
    {
      data->tools.square_act = 1;
      take_mouse_pos(data);
      mouse_pos = take_mouse_pos(data);
      size_x = mouse_pos.x - data->square.init_pos.x;
      size_y = mouse_pos.y - data->square.init_pos.y;
      fill_data(data, mouse_pos);
      if (size_x > 0 && size_y > 0)
	{
	  data->square.pix_square = bunny_new_pixelarray(size_x, size_y);
	  set_bg(data->square.pix_square, data->tools.color.full);
	}
      data->square.pass += 1;
    }
}
