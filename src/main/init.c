/*
** init.c for INITIALIZATION in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Jan 25 02:31:39 2016 bougon_p
** Last update Wed Jan 27 07:42:58 2016 bougon_p
*/

#include "paint.h"

void	back_make(t_data *data)
{
  int			i;
  int			j;
  t_bunny_position	pos;
  t_color		*color;
  t_color		*grey;
  t_color		*final;

  i = 0;
  final = bunny_malloc(sizeof(t_color));
  while (i < data->pixlogo->clipable.clip_width)
    {
      j = data->pixlogo->clipable.clip_height - 1;
      while (j > 0)
	{
	  pos.y = j;
	  pos.x = i;
	  color = (t_color*)data->pixlogo->pixels +
	      (i + (j * data->pixlogo->clipable.clip_width));
	  grey = (t_color*)data->pixback->pixels +
	      (i + (j * data->pixback->clipable.clip_width));
	  final->argb[0] = (color->argb[0] + grey->argb[0] * 4) / 5;
	  final->argb[1] = (color->argb[1] + grey->argb[1] * 4) / 5;
	  final->argb[2] = (color->argb[2] + grey->argb[2] * 4) / 5;
	  tekpixel(data->pixback, poser(i, j + 170, &pos)[0], final);
      	  j--;
	}
      i++;
  }
  bunny_free(final);
}

int	init_all_pixarray(t_data *data)
{
  data->sup->pixarray = NULL;
  data->pixback = bunny_new_pixelarray(PAINT_WIDTH, PAINT_HEIGHT);
  data->pixbg = bunny_new_pixelarray(WIN_WIDTH, WIN_HEIGHT);
  data->pixinfo = bunny_new_pixelarray(WIN_WIDTH, 20);
  data->pixinfocolor = bunny_new_pixelarray(64, 64);
  data->pixbgtool = bunny_new_pixelarray(245, 300);
  data->pixbgcalc = bunny_new_pixelarray(245, 260);
  data->swatch.pix = bunny_new_pixelarray(255, 100);
  data->swatch.pix2 = bunny_new_pixelarray(255, 30);
  set_bg(data->pixback, GREY2);
  set_bg(data->pixbg, GREY);
  set_bg(data->pixinfo, GREY3);
  set_bg(data->pixbgtool, GREY2);
  set_bg(data->pixbgcalc, GREY2);
  back_make(data);
  data->txt = bunny_malloc(sizeof(char *) * 30);
  return (0);
}

int	init_tab_tools(t_tools *tools)
{
  void  (**tabtools)(void *data);

  if ((tabtools = bunny_malloc(sizeof(t_tools) * 7)) == NULL)
    return (1);
  tabtools[0] = &draw_pen;
  tabtools[1] = &draw_circle;
  tabtools[2] = &draw_square;
  tabtools[3] = &erase;
  tabtools[4] = &the_pen;
  tabtools[5] = &use_bucket;
  tabtools[6] = &background;
  tabtools[7] = &invers_color;
  tabtools[8] = &draw_line;
  tools->tabtools = tabtools;
  return (0);
}

int	init_main_variables(t_data *data)
{
  data->sup->pixarray = NULL;
  data->square.pix_square = NULL;
  init_tab_tools(&data->tools);
  data->pen.sec_pt = -1;
  data->tools.line_act = 0;
  data->line.pass = -1;
  data->crs.left_click = 0;
  data->crs.right_click = 0;
  data->crs.tool = bunny_malloc(sizeof(char) * 50);
  data->crs.tool = "Chroma";
  data->tools.size = 5;
  data->tools.color.full = BLACK;
  data->square.pass = -1;
  if((data->pixlogo = bunny_load_pixelarray("img/bg.png")) == NULL)
    return (1);
  if ((data->font = bunny_load_picture("img/font.png")) != NULL)
    {
      data->font->scale.x = 2;
      data->font->scale.y = 2;
    }
  return (0);
}
