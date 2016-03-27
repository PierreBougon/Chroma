/*
** actions_buttons.c for BUTTON in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 20 22:44:39 2016 bougon_p
** Last update Tue Feb 16 21:50:18 2016 bougon_p
*/

#include "paint.h"

void	addcalc(t_data *data, char *name)
{
  if (size(data->sup->calc) < 4 && data->sup->pixarray!= NULL)
    {
      push_front(data->sup->calc, create_calc(data, name));
      display_it(data, data->pixbgcalc, WIN_WIDTH - 255, WIN_HEIGHT - 282);
      dtraverse(data->sup->calc, display_button_calc, data);
      data->crs.left_click = 0;
    }
}

void	create_draw_array(t_data *data)
{
  if (data->sup->pixarray != NULL)
    bunny_delete_clipable(&data->sup->pixarray->clipable);
  data->sup->pixarray = bunny_new_pixelarray(1000, 700);
  data->sup->pos.x = 78 + (data->pixback->clipable.clip_width / 2 -
			   data->sup->pixarray->clipable.clip_width / 2);
  data->sup->pos.y = 2 + (data->pixback->clipable.clip_height / 2 -
			  data->sup->pixarray->clipable.clip_height / 2);
  set_bg(data->sup->pixarray, (unsigned int)WHITE);
}

void	create_img_area(t_data *data)
{
  addcalc(data, "-img-");
  if (data->crs.calc->pix != NULL)
    bunny_delete_clipable(&data->crs.calc->pix->clipable);
  if (data->sup->name != NULL)
    {
      data->crs.calc->pix = bunny_load_pixelarray(data->sup->name);
    }
}

void	check_action_button(void *buttone, t_data *data)
{
  t_button	*button;

  button = (t_button*)buttone;
  if (button->active)
    {
      data->crs.tool = button->link;
      if (my_strcmp(button->link, "create") == 0)
	{
	  create_draw_array(data);
	  addcalc(data, "*BG*");
	  button->active = 0;
	}
      else if (my_strcmp(button->link, "open") == 0)
	{
	  if (data->sup->name != NULL && data->sup->pixarray != NULL)
	    create_img_area(data);
	  button->active = 0;
	}
      /* else if (my_strcmp(button->link, "save") == 0) */
      /* 	{ */
      /* 	  if (data->sup->pixarray != NULL) */
      /* 	    bunny_save_pixelarray(data->sup->pixarray, "save.png"); */
      /* 	  button->active = 0; */
      /* 	} */
      else if (my_strcmp(button->link, "calque") == 0)
	{
	  addcalc(data, "-new-");
	  button->active = 0;
	}
      else if (my_strcmp(button->link, "delete") == 0)
  	{
	  if (remove_cond(data->sup->calc, calc_is_select, free_calc) > 0)
	    {
	      data->sup->nb = 0;
	      dtraverse(data->sup->calc, set_nbr_calc, data);
	      data->sup->nb = size(data->sup->calc);
	      display_it(data, data->pixbgcalc, WIN_WIDTH - 255, WIN_HEIGHT - 282);
	      dtraverse(data->sup->calc, display_button_calc, data);
	    }
	  data->crs.left_click = 0;
  	  button->active = 0;
  	}
    }
}
