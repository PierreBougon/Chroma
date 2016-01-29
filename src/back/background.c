/*
** background.c for BACKGROUND in /home/bougon_p/rendu/gfx_tekpaint/src
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Jan 25 02:41:57 2016 bougon_p
** Last update Wed Jan 27 01:18:23 2016 THEIS Paul
*/

# include "paint.h"

void		background(void *_data)
{
  t_data	*data;

  data = _data;
  set_bg(data->crs.calc->pix, data->tools.color.full);
}
