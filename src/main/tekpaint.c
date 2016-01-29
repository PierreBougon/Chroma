/*
** tekpaint.c for tekpaint in /home/theis_p/gfx_tekpaint/src/main/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Wed Jan 27 07:13:12 2016 THEIS Paul
** Last update Wed Jan 27 07:42:29 2016 bougon_p
*/

#include "paint.h"

t_bunny_response	click_actions(t_bunny_event_state state,
				      t_bunny_mousebutton button, void *_data)
{
  t_data		*data;

  data = _data;
  if (button == BMB_LEFT && state == GO_DOWN)
    {
      data->crs.left_click = 1;
      data->line.pass = 0;
    }
  if (button == BMB_RIGHT && state == GO_DOWN && data->sup->is_drag == 0)
    {
      data->crs.right_click = 1;
      data->sup->drag.x = data->crs.calc->pos.x - data->crs.pencil_pos.x;
      data->sup->drag.y = data->crs.calc->pos.y - data->crs.pencil_pos.y;
      data->sup->is_drag = 1;
    }
  else if (button == BMB_RIGHT && state == GO_UP)
    {
      data->crs.right_click = 0;
      data->sup->is_drag = 0;
    }
  if (button == BMB_LEFT && state == GO_UP)
    {
      data->line.pass = 1;
      if (data->line.pass == 1 && data->tools.line_act == 1)
      	get_line_final(data);
      data->square.pass = -1;
      data->crs.left_click = 0;
      data->pen.sec_pt = -1;
    }
  return (GO_ON);
}

t_bunny_response	key_actions(t_bunny_event_state state,
				    t_bunny_keysym keysym, void *_data)
{
  t_data		*data;

  data = _data;
  if (keysym == BKS_LEFT && state == GO_DOWN && data->tools.size > 3)
    data->tools.size -= 2;
  if (keysym == BKS_RIGHT && state == GO_DOWN && data->tools.size < 120)
    data->tools.size += 2;
  if (keysym == BKS_SPACE && state == GO_DOWN)
    replace_draw_area(data);
  if (keysym == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	mainloop(void *_data)
{
  t_data		*data;

  data = (t_data *)_data;
  display_pos(data);
  dtraverse(data->tool, display_button, data);
  start(data);
  set_color_tool(data);
  set_bg(data->sup->pixarray, WHITE);
  dtraverse(data->sup->calc, add_calc, data);
  display_it(data, data->pixback, 78, 2);
  display_it(data, data->sup->pixarray, data->sup->pos.x, data->sup->pos.y);
  display_it(data, data->swatch.pix, WIN_WIDTH - 260, 5);
  display_it(data, data->swatch.pix2, WIN_WIDTH - 260, 112);
  display_it(data, data->pixinfo, 0, WIN_HEIGHT - 20);
  set_bg(data->pixinfocolor, data->tools.color.full);
  display_it(data, data->pixinfocolor, 7, WIN_HEIGHT - 87);
  display_it(data, data->square.pix_square,
	     data->square.init_pos.x, data->square.init_pos.y);
  display_text(data, data->crs.tool, 10, WIN_HEIGHT - 18);
  display_pos(data);
  bunny_display(data->window);
  dtraverse(data->sup->calc, check_button_calc, data);
  draw(data);
  return (GO_ON);
}

int		main(int ac, char **av)
{
  t_data	data;

  set_max_heap_size(30);
  data.sup = bunny_malloc(sizeof(struct s_support));
  if (ac == 2)
    data.sup->name = av[1];
  else
    data.sup->name = NULL;
  data.sup->pos.x = 0;
  data.sup->pos.y = 0;
  if (init_button(&data) == 1)
    return (1);
  init_main_variables(&data);
  init_all_pixarray(&data);
  data.window = bunny_start(WIN_WIDTH, WIN_HEIGHT, 0, "Chroma");
  display_it(&data, data.pixbg, 0, 0);
  display_it(&data, data.pixbgtool, WIN_WIDTH - 255, 150);
  display_it(&data, data.pixbgcalc, WIN_WIDTH - 255, WIN_HEIGHT - 282);
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(key_actions);
  bunny_set_click_response(click_actions);
  bunny_loop(data.window, 60, &data);
  bunny_stop(data.window);
  delete_all_clipables(&data);
  empty_list(data.tool, free_calc);
  bunny_free(data.tool);
  return (0);
}
