/*
** line.c for line in /home/goubea_t/graph/gfx_tekpaint/src/line
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Wed Jan 27 03:16:53 2016 Tristan goubeau
** Last update Wed Jan 27 05:28:10 2016 Tristan goubeau
*/

#include "paint.h"

void	get_line_init(void *_data)
{
  t_data			*data;
  const t_bunny_position	*pos;

  data = _data;
  pos = bunny_get_mouse_position();
  data->line.init_pos.x = pos->x - data->crs.calc->pos.x;
  data->line.init_pos.y = pos->y - data->crs.calc->pos.y;
}

void	draw_final_line(void *_data)
{
  t_data		*data;
  t_bunny_position	*pos;

  data = _data;
  if ((pos = bunny_malloc(sizeof(t_bunny_position *) * 2)) == NULL)
    return ;
  pos[0].x = data->line.init_pos.x;
  pos[0].y = data->line.init_pos.y;
  pos[1].x = data->line.final_pos.x;
  pos[1].y = data->line.final_pos.y;
  tekline(data->crs.calc->pix, pos, &data->tools.color);
  data->line.pass = -1;
  data->tools.line_act = 0;
}

void	get_line_final(void *_data)
{
  t_data			*data;
  const t_bunny_position	*pos;

  data = _data;
  pos = bunny_get_mouse_position();
  data->line.final_pos.x = pos->x - data->crs.calc->pos.x;
  data->line.final_pos.y = pos->y - data->crs.calc->pos.y;
  draw_final_line(data);
}

void	draw_line(void *_data)
{
  t_data		*data;

  data = _data;
  data->tools.line_act = 1;
  if (data->line.pass == 0)
    {
      get_line_init(data);
      data->line.pass = -1;
    }
}
