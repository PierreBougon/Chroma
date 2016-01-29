/*
** pen.c for pen in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Jan  8 02:24:14 2016 bougon_p
** Last update Wed Jan 27 03:18:30 2016 THEIS Paul
*/

#include "paint.h"

void			fill_line(t_data *data, int cond)
{
  t_bunny_position	*pos;

  if ((pos = bunny_malloc(sizeof(t_bunny_position) * 2)) == NULL)
    return ;
  if (cond == 1)
    draw_lines_right(data, pos);
  else if (cond == 2)
    draw_lines_left(data, pos);
  bunny_free(pos);
}

void	choose_direction(t_data *data, int next_bool)
{
      if ((data->pen.previous_pos.y > data->pen.next_pos.y
       && data->pen.previous_pos.x < data->pen.next_pos.x)
      || (data->pen.previous_pos.y < data->pen.next_pos.y
	  && data->pen.previous_pos.x > data->pen.next_pos.x))
    fill_line(data, 1);
  else
    fill_line(data, 2);
  data->pen.previous_pos = data->pen.next_pos;
  data->pen.sec_pt = next_bool;
}

void	check_pass(t_data *data)
{
  if (data->pen.sec_pt == -1)
    {
      data->pen.previous_pos = data->pen.next_pos;
      data->pen.sec_pt = 1;
    }
  else if (data->pen.sec_pt == 0 && data->pen.sec_pt != -1)
    choose_direction(data, 1);
  else if (data->pen.sec_pt == 1)
    choose_direction(data, 0);
}

void				draw_pen(void *_data)
{
  t_data			*data;
  const t_bunny_position	*mouse_pos;
  t_posrec			rec;

  data = _data;
  rec.color.full = data->tools.color.full;
  mouse_pos = bunny_get_mouse_position();
  data->pen.next_pos = *mouse_pos;
  data->pen.next_pos.x -= data->crs.calc->pos.x;
  data->pen.next_pos.y -= data->crs.calc->pos.y;
  rec.x = mouse_pos->x - data->crs.calc->pos.x - data->tools.size / 2;
  rec.y = mouse_pos->y - data->crs.calc->pos.y - data->tools.size / 2;
  my_setsquare(data->crs.calc->pix, rec, data->tools.size, data->tools.size);
  check_pass(data);
}

void				the_erase(void *_data)
{
  t_data			*data;
  const t_bunny_position	*mouse_pos;
  t_posrec			rec;
  t_color			col;

  data = _data;
  col = data->tools.color;
  data->tools.color.full = 0x00000000;
  rec.color.full = data->tools.color.full;
  mouse_pos = bunny_get_mouse_position();
  data->pen.next_pos = *mouse_pos;
  data->pen.next_pos.x -= data->crs.calc->pos.x;
  data->pen.next_pos.y -= data->crs.calc->pos.y;
  rec.x = mouse_pos->x - data->crs.calc->pos.x - data->tools.size / 2;
  rec.y = mouse_pos->y - data->crs.calc->pos.y - data->tools.size / 2;
  my_setsquare(data->crs.calc->pix, rec, data->tools.size, data->tools.size);
  check_pass(data);
  data->tools.color = col;
}
