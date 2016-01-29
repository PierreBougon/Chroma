/*
** paint.h for tekpaint in /home/theis_p/gfx_tekpaint/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Mon Jan  4 19:15:49 2016 bougon_p
** Last update Wed Jan 27 07:19:48 2016 THEIS Paul
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include "list.h"

typedef struct		s_square
{
  t_bunny_pixelarray	*pix_square;
  t_bunny_position	init_pos;
  t_bunny_position	final_pos;
  int			sizex;
  int			sizey;
  int			pass;
}			t_square;

typedef struct		s_line
{
  t_bunny_position	init_pos;
  t_bunny_position	final_pos;
  int			pass;
}			t_line;

typedef struct		s_pen
{
  t_bunny_position	previous_pos;
  t_bunny_position	next_pos;
  int			sec_pt;
}			t_pen;

typedef struct		s_button
{
  t_bunny_position	pos;
  t_bunny_pixelarray	*pix;
  char			*name;
  char			*link;
  int			active;
}			t_button;

typedef struct		s_calc
{
  t_bunny_position	pos;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*button;
  char			*name;
  int			active;
  int			hide;
  int			id;
}			t_calc;

typedef struct		s_swatch
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*pix2;
  t_color		col_tofade;
}			t_swatch;

typedef struct		s_support
{
  t_bunny_pixelarray    *pixarray;
  t_bunny_position	pos;
  t_bunny_position	drag;
  int			is_drag;
  int			nb;
  list			*calc;
  char			*name;
}			t_support;

typedef struct		s_tools
{
  int			size;
  t_color		color;
  void			(**tabtools)(void *data);
  int			pencil_act;
  int			circle_act;
  int			square_act;
  int			eraser_act;
  int			pen_act;
  int			line_act;
  int			bucket_act;
}			t_tools;

typedef	struct		s_crs
{
  int			pencil_size;
  int			pencil;
  int			left_click;
  int			right_click;
  char			*tool;
  t_bunny_position	pencil_pos;
  t_calc		*calc;
}			t_crs;

typedef struct          s_data
{
  t_bunny_window        *window;
  t_support		*sup;
  t_bunny_pixelarray    *pixlogo;
  t_bunny_pixelarray	*pixbg;
  t_bunny_pixelarray	*pixback;
  t_bunny_pixelarray	*pixinfo;
  t_bunny_pixelarray	*pixinfocolor;
  t_swatch		swatch;
  t_bunny_pixelarray	*pixbgtool;
  t_bunny_pixelarray	*pixbgcalc;
  t_bunny_position	pos_drawarray;
  t_bunny_ini		*ini;
  t_pen			pen;
  t_tools		tools;
  t_crs			crs;
  list			*tool;
  t_bunny_picture	*font;
  t_square		square;
  t_line		line;
  char			*txt;
}			t_data;

typedef void (*list_op2)(void*, t_data*);

#endif /* !STRUCT_H_ */
