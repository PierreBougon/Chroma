/*
** button.c for button in /home/goubea_t/graph/gfx_tekpaint
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Tue Jan 26 20:35:21 2016 Tristan goubeau
** Last update Wed Jan 27 05:12:14 2016 THEIS Paul
*/

#include "paint.h"

t_button	*create_button(t_bunny_pixelarray *pix, t_bunny_position pos,
				const char *linke)
{
  t_button	*s;
  char		*link;

  s = bunny_malloc(sizeof(t_calc));
  link = bunny_malloc((strlen(linke) + 1) * sizeof(char));
  strncpy(link, linke, strlen(linke) + 1);
  s->pix = pix;
  s->link = link;
  s->pos = pos;
  s->active = 0;
  return (s);
}

void		disable(void *data)
{
  t_button 	*s;

  s = data;
  s->active = 0;
}

void				display_button(void *buttone, t_data *data)
{
  t_bunny_pixelarray            *pix;
  t_button			*button;

  button = (t_button*)buttone;
  if ((data->crs.pencil_pos.x - 64 <= button->pos.x && data->crs.pencil_pos.x >= button->pos.x)
      && (data->crs.pencil_pos.y - 64 <= button->pos.y && data->crs.pencil_pos.y >= button->pos.y) &&
      data->crs.left_click == 1)
    {
      traverse(data->tool, disable);
      button->active = 1;
      dtraverse(data->tool, check_action_button, data);
    }
  if (button->active == 1)
    {
      pix = shade_of_grey(button->pix);
      bunny_blit(&data->window->buffer, &(pix)->clipable, &button->pos);
      bunny_delete_clipable(&(pix)->clipable);
    }
  else
    bunny_blit(&data->window->buffer, &button->pix->clipable, &button->pos);
}

void		free_button(void *data)
{
  t_button *s;

  s = data;
  bunny_free(s->link);
  bunny_free(s);
}
