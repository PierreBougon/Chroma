/*
** free.c for FREE in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Jan 23 01:48:03 2016 bougon_p
** Last update Sat Jan 23 01:55:44 2016 bougon_p
*/

#include "paint.h"

void	delete_all_clipables(t_data *data)
{
  if (data->sup->pixarray != NULL)
    bunny_delete_clipable(&data->sup->pixarray->clipable);
  if (data->pixbg != NULL)
    bunny_delete_clipable(&data->pixbg->clipable);
  if (data->pixback != NULL)
    bunny_delete_clipable(&data->pixback->clipable);
  if (data->pixinfo != NULL)
    bunny_delete_clipable(&data->pixinfo->clipable);
  if (data->pixinfocolor != NULL)
    bunny_delete_clipable(&data->pixinfocolor->clipable);
  if (data->pixbgtool != NULL)
    bunny_delete_clipable(&data->pixbgtool->clipable);
  if (data->pixbgcalc != NULL)
    bunny_delete_clipable(&data->pixbgcalc->clipable);
}
