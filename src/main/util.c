/*
** util.c for tekpaint in /home/theis_p/gfx_tekpaint/src/pen/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Jan 22 03:58:19 2016 THEIS Paul
** Last update Wed Jan 27 07:57:18 2016 bougon_p
*/

#include "paint.h"
#include "list.h"

int	drag(t_data *data)
{
  data->crs.calc->pos.x = data->sup->drag.x + (bunny_get_mouse_position())[0].x;
  data->crs.calc->pos.y = data->sup->drag.y + (bunny_get_mouse_position())[0].y;
  return (1);
}

int		check_active_tool(t_data *data)
{
  node		*tmp;
  unsigned int	i;
  t_button	*tmp_data;

  tmp = data->tool->head;
  i = 0;
  while (i < data->tool->size)
    {
      tmp_data = tmp->data;
      if (tmp_data->active == 1)
	return (i);
      tmp = tmp->next;
      i++;
    }
  return (-1);
}

void		special_actions(t_data *data, int num_tool)
{
  node		*tmp;
  int		i;
  t_button	*tmp_data;

  if (num_tool == 2)
    {
      if (data->square.pix_square != NULL)
	{
	  bunny_delete_clipable(&data->square.pix_square->clipable);
	}
    }
  if (num_tool == 6)
    {
      tmp = data->tool->head;
      i = 0;
      while (i++ < 6)
  	tmp = tmp->next;
      tmp_data = tmp->data;
      tmp_data->active = 0;
    }
}

int	draw(t_data *data)
{
  int	num_tool;

  if ((num_tool = check_active_tool(data)) == -1)
    return (1);
  num_tool -= 4;
  if (data->crs.left_click == 1 && data->sup->pixarray != NULL && num_tool < 9)
    {
      special_actions(data, num_tool);
      data->tools.tabtools[num_tool](data);
    }
  if (data->crs.right_click == 1 && data->sup->pixarray != NULL)
    drag(data);
  return (0);
}
