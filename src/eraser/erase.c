/*
** erase.c for ERASER in /home/bougon_p/rendu/gfx_tekpaint/src
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Jan 23 04:42:59 2016 bougon_p
** Last update Wed Jan 27 01:11:30 2016 THEIS Paul
*/

#include "paint.h"

void		erase(void *_data)
{
  t_data	*data;

  data = _data;
  the_erase(data);
  return ;
}
