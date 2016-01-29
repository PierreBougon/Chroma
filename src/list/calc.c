/*
** calc.c for calc in /home/goubea_t/graph/gfx_tekpaint
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Tue Jan 26 22:16:57 2016 Tristan goubeau
** Last update Wed Jan 27 08:25:17 2016 bougon_p
*/

#include "paint.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

t_color		*get_calc_color(t_bunny_pixelarray *pix, int x, int y)
{
  t_color       *color;

  color = (t_color *)pix->pixels + x +
    (y * pix->clipable.clip_width);
  return (color);
}

void		disable_calc(void *data)
{
  t_calc 	*s;

  s = data;
  s->active = 0;
}

void		hide_calc(void *data)
{
  t_calc 	*s;

  s = data;
  s->hide = 0;
}

void		add_calc(void *calci, t_data *data)
{
  t_calc	*calc;
  t_color	*a;
  int		i;
  int		j;
  t_bunny_position	*pos;

  calc = (t_calc *)calci;
  data= data;
  i = 0;
  pos = bunny_malloc(sizeof(t_bunny_position));
  while (i < data->crs.calc->pix->clipable.clip_width)
    {
      j = 0;
      while (j < data->crs.calc->pix->clipable.clip_height)
	{
	  a = get_calc_color(calc->pix, i, j);
	  if (a->argb[3] != 0 && calc->hide == 0)
	    dtekpixel(data->sup->pixarray, poser
		      (i -(data->sup->pos.x - calc->pos.x),
		       j - (data->sup->pos.y - calc->pos.y), pos)[0], a);
	  j++;
	}
      i++;
    }
}

t_calc			*create_calc(t_data *data, const char* first_name)
{
  t_calc 		*s;
  char			*name;
  t_bunny_position	pos;
  t_bunny_pixelarray	*pix;

  s = bunny_malloc(sizeof(t_calc));
  pix = bunny_new_pixelarray(data->sup->pixarray->clipable.clip_width,
			     data->sup->pixarray->clipable.clip_height);
  set_bg(pix, 0x00000000);
  name = bunny_malloc((strlen(first_name) + 1)*sizeof(char));
  strncpy(name, first_name, strlen(name) + 1);
  pos.x = 78 + (data->pixback->clipable.clip_width / 2 -
		data->sup->pixarray->clipable.clip_width / 2);
  pos.y = 2 + (data->pixback->clipable.clip_height / 2 -
	       data->sup->pixarray->clipable.clip_height / 2);
  s->pix = pix;
  s->button = bunny_new_pixelarray(200, 19);
  s->name = bunny_malloc(sizeof(char) * 50);
  strcat(s->name, setnbr(data->sup->nb));
  strcat(s->name, " : ");
  strcat(s->name, name);
  s->pos = pos;
  s->active = 1;
  s->hide = 0;
  s->id = data->sup->nb++;
  traverse(data->sup->calc, disable_calc);
  data->crs.calc = s;
  return (s);
}

void		free_calc(void *data)
{
  t_calc	*s;

  s = data;
  bunny_delete_clipable(&s->pix->clipable);
  bunny_free(s->name);
  bunny_free(s);
}

void				check_button_calc(void *calci, t_data *data)
{
  t_calc			*calc;

  calc = (t_calc *)calci;
  if (calc == NULL)
    return ;
  if (data->crs.pencil_pos.x - 253 <= WIN_WIDTH - 50
      && data->crs.pencil_pos.x >= WIN_WIDTH - 253 &&
      data->crs.pencil_pos.y - 20 <= (WIN_HEIGHT - 280 +
				      ((data->sup->nb - 1 - calc->id)
					    * 20)) &&
      data->crs.pencil_pos.y >= (WIN_HEIGHT - 280 +
				 ((data->sup->nb - 1 - calc->id)
				       * 20)) && data->crs.left_click == 1)
    {
      traverse(data->sup->calc, disable_calc);
      calc->active = 1;
      dtraverse(data->sup->calc, display_button_calc, data);
      data->crs.calc = calc;
    }
    if (data->crs.pencil_pos.x - 253 <= WIN_WIDTH
	&& data->crs.pencil_pos.x >= WIN_WIDTH - 50 &&
	data->crs.pencil_pos.y - 20 <= (WIN_HEIGHT - 280
					+ ((data->sup->nb - 1 - calc->id)
					      * 20)) &&
	data->crs.pencil_pos.y >= (WIN_HEIGHT - 280 + ((data->sup->nb - 1 - calc->id)
					 * 20)) && data->crs.left_click == 1)
    {
      calc->hide = (calc->hide) ? 0 : 1;
      calc->active = 0;
      dtraverse(data->sup->calc, display_button_calc, data);
      data->crs.left_click = 0;
    }
}

void				display_button_calc(void *calc, t_data *data)
{
  if (((t_calc*)calc)->id > (size(data->sup->calc) - 4))
    {
      if (((t_calc*)calc)->active == 1)
	set_bg(((t_calc*)calc)->button, GREY);
      else if (((t_calc*)calc)->hide == 1)
	set_bg(((t_calc*)calc)->button, GREY3);
      else
	set_bg(((t_calc*)calc)->button, GREY2);
      display_it(data, ((t_calc*)calc)->button, WIN_WIDTH - 253, WIN_HEIGHT -
		 280 + ((size(data->sup->calc) - ((t_calc*)calc)->id) * 20));
      display_text(data, ((t_calc*)calc)->name, WIN_WIDTH - 250, WIN_HEIGHT -
		   280 + ((size(data->sup->calc) - ((t_calc*)calc)->id) * 20));
      display_text(data, "  o", WIN_WIDTH - 50, WIN_HEIGHT -
		   280 + ((size(data->sup->calc) - ((t_calc*)calc)->id) * 20));
    }
}
