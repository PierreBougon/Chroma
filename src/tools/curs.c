/*
** curs.c for curs in /home/theis_p/fantasy2_2020/Colle4
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Thu Jan 14 03:02:28 2016 Paul THEIS
** Last update Wed Jan 27 08:08:33 2016 bougon_p
*/

#include "paint.h"

t_bunny_position	*poser(int x, int y, t_bunny_position *pos)
{
  pos[0].x = x;
  pos[0].y = y;
  return (pos);
}

void	circle2(t_data *data, t_bunny_position *pos, int x, int y)
{
  t_color	col;

  col.full = data->tools.color.full;
  dtekpixel(data->crs.calc->pix,
	   poser(pos[1].x + x, pos[1].y + y, pos)[0], &col);
  dtekpixel(data->crs.calc->pix,
	   poser(pos[1].x + y, pos[1].y + x, pos)[0], &col);
  dtekpixel(data->crs.calc->pix,
	   poser(pos[1].x - x, pos[1].y + y, pos)[0], &col);
  dtekpixel(data->crs.calc->pix,
	   poser(pos[1].x - y, pos[1].y + x, pos)[0], &col);
  dtekpixel(data->crs.calc->pix,
	   poser(pos[1].x + x, pos[1].y - y, pos)[0], &col);
  dtekpixel(data->crs.calc->pix,
	   poser(pos[1].x + y, pos[1].y - x, pos)[0], &col);
  dtekpixel(data->crs.calc->pix,
	   poser(pos[1].x - x, pos[1].y - y, pos)[0], &col);
  dtekpixel(data->crs.calc->pix,
	   poser(pos[1].x - y, pos[1].y - x, pos)[0], &col);
}

void	circle(t_bunny_position *pos, int r, t_data *data)
{
  int   x = 0;
  int   y = r;
  int   d = r - 1;

  while (y >= x)
    {
      circle2(data, pos, x, y);
      if (d >= 2 * x)
        {
          d = d - 2 * x - 1;
          x = x + 1;
        }
      else if (d < 2 * (r - y))
        {
          d = d + 2 * y - 1;
          y = y - 1;
        }
      else
        {
          d = d + 2 * (y - x - 1);
          y = y - 1;
          x = x + 1;
        }
    }
}

void	rond(t_bunny_position *pos, int r, t_data *data)
{
  while (0 <= r)
    {
      circle(pos, r, data);
      r--;
    }
}
