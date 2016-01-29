/*
** rec.c for rec in /home/bougon_p/rendu/gfx_fdf1
**
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Nov 20 15:07:03 2015 Pierre Bougon
** Last update Wed Jan 20 07:48:30 2016 THEIS Paul
*/

#include "paint.h"

void			my_setsquare(t_bunny_pixelarray *pix,
                                     t_posrec posrec,
                                     int height, int width)
{
  int                   i;
  int                   j;
  t_bunny_position      pos;

  i = posrec.x;
  j = posrec.y;
  while (j < posrec.y + width)
    {
      while (i < posrec.x + height)
        {
          pos.x = i;
	  pos.y = j;
          dtekpixel(pix, pos, &posrec.color);
          i++;
        }
      i = posrec.x;
      j++;
    }
}
