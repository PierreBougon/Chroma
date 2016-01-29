/*
** tekline.c for LINE in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Jan 18 04:57:21 2016 bougon_p
** Last update Wed Jan 27 05:29:02 2016 Tristan goubeau
*/

#include "paint.h"

void		teklinex(t_bunny_pixelarray *array,
			 t_bunny_position *tmp, t_color *color)
{
  int           i;
  int           cumul;

  i = 1;
  cumul = tmp[1].y / 2 ;
  while (i <= tmp[1].y)
    {
      tmp[0].y += tmp[2].y ;
      cumul += tmp[1].x ;
      if (cumul >= tmp[1].y)
	{
	  cumul -= tmp[1].y ;
	  tmp[0].x += tmp[2].x ;
	}
      dtekpixel(array, tmp[0], color) ;
      i++;
    }
}

void		tekliney(t_bunny_pixelarray *array,
			 t_bunny_position *tmp, t_color *color)
{
  int           i;
  int           cumul;

  i = 1;
  cumul = tmp[1].x / 2;
  while (i <= tmp[1].x)
    {
      tmp[0].x += tmp[2].x;
      cumul += tmp[1].y;
      if ( cumul >= tmp[1].x )
	{
	  cumul -= tmp[1].x;
	  tmp[0].y += tmp[2].y;
	}
      dtekpixel(array, tmp[0], color);
      i++;
    }
}

int			tekline(t_bunny_pixelarray *array,
				t_bunny_position *pos, t_color *color)
{
  t_bunny_position      *tmp;

  if ((tmp = bunny_malloc(sizeof(t_bunny_position) * 3)) == NULL)
    return (1);
  tmp[0].x = pos[0].x;
  tmp[0].y = pos[0].y;
  tmp[1].x = pos[1].x - pos[0].x;
  tmp[1].y = pos[1].y - pos[0].y;
  tmp[2].x = ( tmp[1].x > 0 ) ? 1 : -1;
  tmp[2].y = ( tmp[1].y > 0 ) ? 1 : -1;
  tmp[1].x = abs(tmp[1].x);
  tmp[1].y = abs(tmp[1].y);
  dtekpixel(array, tmp[0], color);
  if (tmp[1].x < tmp[1].y)
    teklinex(array, tmp, color);
  else
    tekliney(array, tmp, color);
  return (0);
}
