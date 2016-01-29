/*
** display.c for tekpaint in /home/theis_p/gfx_tekpaint/src/main/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Jan 22 05:42:24 2016 THEIS Paul
** Last update Wed Jan 27 08:20:17 2016 bougon_p
*/

#include "paint.h"

void				display_pos(t_data *data)
{
  const t_bunny_position	*pos;
  int				i;
  char				*str;

  pos = bunny_get_mouse_position();
  data->crs.pencil_pos.x = pos[0].x;
  data->crs.pencil_pos.y = pos[0].y;
  if (pos[0].x >= 78 && pos[0].x <= PAINT_WIDTH + 78 &&
      pos[0].y >= 2 && pos[0].y <= PAINT_HEIGHT + 2)
    {
      i = 0;
      while (data->txt[i++] != 0)
	data->txt[i - 1] = 0;
      strcpy(data->txt,"X: ");
      if ((str = setnbr(pos[0].x)) != NULL)
	{
	  my_strcat(data->txt, str);
	}
      my_strcat(data->txt, " \x7F ");
      my_strcat(data->txt, "Y: ");
      if ((str = setnbr(pos[0].y)) != NULL)
	{
	  my_strcat(data->txt, setnbr(pos[0].y));
	}
      display_text(data, data->txt, WIN_WIDTH - 200, WIN_HEIGHT - 18);

    }
}

void			display_it(t_data *data, t_bunny_pixelarray *pix,
				   int x, int y)
{
  t_bunny_position	pos;

  pos.x = x;
  pos.y = y;
  if (pix != NULL)
    bunny_blit(&data->window->buffer, &pix->clipable, &pos);
}

void			display_text(t_data *data, char *str,
				   int x, int y)
{
  t_bunny_position	pos;

  pos.x = x;
  pos.y = y;
  if (data->font != NULL)
    say(data->font, &data->window->buffer, &pos, str);
}

void			set_bg(t_bunny_pixelarray *pixarray, unsigned int color)
{
  t_bunny_position      pos;
  t_color               col;
  int                   i;
  int                   j;

  j = 0;
  col.full = color;
  if (pixarray != NULL)
    {
      while (j < pixarray->clipable.clip_height)
	{
	  i = 0;
	  while (i < pixarray->clipable.clip_width)
	    {
	      pos.x = i;
	      pos.y = j;
	      tekpixel(pixarray, pos, &col);
	      i++;
	    }
	  j++;
	}
    }
}
