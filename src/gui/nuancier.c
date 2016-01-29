/*
** nuancier.c for tekpaint in /home/clemen_j/Work/Infographie/gfx_tekpaint/SRC
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Tue Jan 19 20:23:19 2016 Clémenceau Cedric
** Last update Wed Jan 27 06:33:00 2016 THEIS Paul
*/

#include "paint.h"

void	print_color(t_color *color, int i)
{
  if (i >= 0 && i < 85)
    {
      color->argb[0] = 255;
      color->argb[1] += 3;
      color->argb[2] = 0;
    }
  else if (i >= 85 && i < 170)
    {
      color->argb[1] = 255;
      color->argb[2] += 3;
      color->argb[0] -= 3;
    }
  else
    {
      color->argb[2] = 255;
      color->argb[0] += 3;
      color->argb[1] -= 3;
    }
}

void	set_color_tool2(t_data *data)
{
  t_bunny_position	pos[1];

  data->crs.pencil_pos.x = bunny_get_mouse_position()[0].x;
  data->crs.pencil_pos.y = bunny_get_mouse_position()[0].y;
  if (data->crs.pencil_pos.x - 255 <= WIN_WIDTH - 5 &&
      data->crs.pencil_pos.x >= WIN_WIDTH - 260 &&
      data->crs.pencil_pos.y >= 2 &&
      data->crs.pencil_pos.y <= 102 &&
      data->crs.left_click == 1)
{
      data->tools.color.full = getpixelcolor
	  (data->swatch.pix, poser(data->crs.pencil_pos.x -
				    (WIN_WIDTH - 260), data->crs.pencil_pos.y - 2, pos));
      data->tools.color.argb[3] = 255;
    }
}

void	set_color_tool(t_data *data)
{
  t_bunny_position	pos[1];

  data->crs.pencil_pos.x = bunny_get_mouse_position()[0].x;
  data->crs.pencil_pos.y = bunny_get_mouse_position()[0].y;
  if (data->crs.pencil_pos.x - 255 <= WIN_WIDTH - 5 &&
      data->crs.pencil_pos.x >= WIN_WIDTH - 260 &&
      data->crs.pencil_pos.y >= 112 &&
      data->crs.pencil_pos.y <= 142 &&
      data->crs.left_click == 1)
{
      data->swatch.col_tofade.full = getpixelcolor
	  (data->swatch.pix2, poser(data->crs.pencil_pos.x -
				    (WIN_WIDTH - 260), 0, pos));
    }
  set_color_tool2(data);
}

int		start(t_data *data)
{
  t_color	color[2];
  int		n;
  int		i;
  t_bunny_position pos[2];

  n = -1;
  while (n <= data->swatch.pix2->clipable.clip_height)
    {
      i = 0;
      while (i <= data->swatch.pix2->clipable.clip_width)
	{
	  print_color(&color[1], i);
	  dtekpixel(data->swatch.pix2, poser(i, n, pos)[0], &color[1]);
	  i++;
	}
      n++;
    }
  fill_swatch(data);
  return (0);
}
