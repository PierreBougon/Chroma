/*
** list3.c for list3 in /home/goubea_t/graph/gfx_tekpaint
**
** Made by Tristan goubeau
** Login   <goubea_t@epitech.net>
**
** Started on  Tue Jan 26 22:42:58 2016 Tristan goubeau
** Last update Wed Jan 27 01:53:56 2016 THEIS Paul
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "paint.h"

int	calc_is_select(const void* calc)
{
  if (((t_calc*)calc)->active == 1)
    return (1);
  else
    return (0);
}

void	set_nbr_calc(void* calc, t_data *data)
{
  ((t_calc*)calc)->id = data->sup->nb++;
}
