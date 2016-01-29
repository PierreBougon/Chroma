/*
** init_button.c for BUTTON in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Jan 25 18:12:26 2016 bougon_p
** Last update Wed Jan 27 04:43:40 2016 THEIS Paul
*/

#include "paint.h"

int			set_menu(char *link, t_data *data)
{
  t_bunny_position      pos;

  if (bunny_ini_get_field(data->ini, "chroma", link, 1) == NULL)
    return (1);
  pos.x = 7;
  pos.y = 5 + 70 *
    my_getnbr((char *)bunny_ini_get_field(data->ini, "chroma", link, 1));
  push_front(data->tool,
             create_button(bunny_load_pixelarray(bunny_ini_get_field(data->ini,
                                                                     "chroma",
                                                                     link, 0)),
                           pos, link));
  return (0);
}

int			set_tool(char *link, t_data *data)
{
  t_bunny_position	pos;

  if (bunny_ini_get_field(data->ini, "chroma", link, 1) == NULL)
    return (1);
  pos.x = (WIN_WIDTH - 240) + 75 *
    my_getnbr((char *)bunny_ini_get_field(data->ini, "chroma", link, 1));
  pos.y = 160 + 70 *
    my_getnbr((char *)bunny_ini_get_field(data->ini, "chroma", link, 2));
  push_front(data->tool,
             create_button(bunny_load_pixelarray(bunny_ini_get_field(data->ini,
                                                                     "chroma",
                                                                     link, 0)),
                           pos, link));
  return (0);
}

int		init_button(t_data *data)
{
  char          *tool;
  int           i;

  if ((tool = bunny_malloc(sizeof(char) * 100)) == NULL)
    return (1);
  data->ini = bunny_load_ini("button.ini");
  data->tool = create_list();
  data->sup->calc = create_list();
  data->sup->nb = 1;
  i = my_getnbr((char *)bunny_ini_get_field(data->ini, "chroma", "nb", 0));
  while (i > 0 && i--)
    {
      if ((tool = (char *)bunny_ini_get_field(data->ini, "chroma", "list", i)) == 0)
	return (1);
      set_tool(tool, data);
    }
  i = my_getnbr((char *)bunny_ini_get_field(data->ini, "chroma", "nb2", 0));
  while (i > 0 && i--)
    {
      if ((tool = (char *)bunny_ini_get_field(data->ini, "chroma", "list2", i)) == 0)
	return (1);
      set_menu(tool, data);
    }
  return (0);
}
