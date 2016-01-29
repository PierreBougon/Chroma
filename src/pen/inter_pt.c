/*
** inter_pt.c for fill the line in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 20 02:00:40 2016 bougon_p
** Last update Wed Jan 27 00:58:27 2016 THEIS Paul
*/

#include "paint.h"

void	cast_left_line(t_data *data, t_bunny_position *pos, int i, int j)
{
  pos[0].x = data->pen.previous_pos.x - i;
  pos[0].y = data->pen.previous_pos.y + j;
  pos[1].x = data->pen.next_pos.x - j;
  pos[1].y = data->pen.next_pos.y + i;
  tekline(data->crs.calc->pix, pos, &data->tools.color);
}

void			draw_lines_left(t_data *data, t_bunny_position *pos)
{
  int                   i;
  int                   j;
  int                   count;

  j = data->tools.size / 2;
  i = data->tools.size / 2;
  count = 0;
  while (count++ < data->tools.size)
    {
      cast_left_line(data, pos, i, j);
      i--;
    }
  i++;
  count = 0;
  while (count++ < data->tools.size)
    {
      pos[0].x = data->pen.previous_pos.x - i;
      pos[0].y = data->pen.previous_pos.y + j;
      pos[1].x = data->pen.next_pos.x - j;
      pos[1].y = data->pen.next_pos.y + i;
      tekline(data->crs.calc->pix, pos, &data->tools.color);
      j--;
    }
}

void	cast_right_line(t_data *data, t_bunny_position *pos, int i, int j)
{
  pos[0].x = data->pen.previous_pos.x - i;
  pos[0].y = data->pen.previous_pos.y - j;
  pos[1].x = data->pen.next_pos.x - j;
  pos[1].y = data->pen.next_pos.y - i;
  tekline(data->crs.calc->pix, pos, &data->tools.color);
}

void			draw_lines_right(t_data *data, t_bunny_position *pos)
{
  int                   i;
  int                   j;
  int                   count;

  j = data->tools.size / 2;
  i = data->tools.size / 2;
  count = 0;
  while (count++ < data->tools.size)
    {
      cast_right_line(data, pos, i, j);
      i--;
    }
  i++;
  count = 0;
  while (count++ < data->tools.size)
    {
      pos[0].x = data->pen.previous_pos.x - i;
      pos[0].y = data->pen.previous_pos.y - j;
      pos[1].x = data->pen.next_pos.x - j;
      pos[1].y = data->pen.next_pos.y - i;
      tekline(data->crs.calc->pix, pos, &data->tools.color);
      j--;
    }
}
