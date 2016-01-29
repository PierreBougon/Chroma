/*
** swatch.c for SWATCH in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Jan 27 02:41:22 2016 bougon_p
** Last update Wed Jan 27 04:09:14 2016 bougon_p
*/

#include "paint.h"

t_color	fade_color(float saver, float saveg, float saveb)
{
  t_color	new_color;

  new_color.argb[0] = (int)saver;
  new_color.argb[1] = (int)saveg;
  new_color.argb[2] = (int)saveb;
  return (new_color);
}

void	draw_linefade(t_bunny_pixelarray *pix, t_bunny_position pos, t_color col)
{
  float			coefr;
  float			coefg;
  float			coefb;
  float			saver;
  float			saveg;
  float			saveb;

  coefr = (float)((float)col.argb[0]) / 100.0;
  coefg = (float)((float)col.argb[1]) / 100.0;
  coefb = (float)((float)col.argb[2]) / 100.0;
  saver = col.argb[0];
  saveg = col.argb[1];
  saveb = col.argb[2];
  while (pos.y < 100)
    {
      saver -= coefr;
      saveg -= coefg;
      saveb -= coefb;
      col = fade_color(saver, saveg, saveb);
      dtekpixel(pix, pos, &col);
      pos.y++;
    }
}

void			draw_swatch(float coefr, float coefg, float coefb, t_data *data)
{
  t_bunny_position	pos;
  float			saver;
  float			saveg;
  float			saveb;
  t_color		col;

  pos.x = 255;
  saver = data->swatch.col_tofade.argb[0];
  saveg = data->swatch.col_tofade.argb[1];
  saveb = data->swatch.col_tofade.argb[2];
  while (pos.x >= 0)
    {
      saver += coefr;
      saveg += coefg;
      saveb += coefb;
      col = fade_color(saver, saveg, saveb);
      pos.y = 0;
      draw_linefade(data->swatch.pix, pos, col);
      pos.x--;
    }
}

void	fill_swatch(t_data *data)
{
  float			coefr;
  float			coefg;
  float			coefb;


  coefr = (float)((float)255.0 - data->swatch.col_tofade.argb[0]) / 255.0;
  coefg = (float)((float)255.0 - data->swatch.col_tofade.argb[1]) / 255.0;
  coefb = (float)((float)255.0 - data->swatch.col_tofade.argb[2]) / 255.0;
  draw_swatch(coefr, coefg, coefb, data);
}
