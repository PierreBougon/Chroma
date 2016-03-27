/*
** paint.h for tekpaint in /home/theis_p/gfx_tekpaint/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Mon Jan  4 19:15:49 2016 bougon_p
** Last update Tue Feb 16 21:43:52 2016 bougon_p
*/

#ifndef PAINT_H_
# define PAINT_H_

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

# include "rec.h"
# include "struct.h"
# include "lapin.h"
# include "list.h"


# define PAINT_WIDTH 1280
# define PAINT_HEIGHT 720
# define WIN_WIDTH (PAINT_WIDTH + 345)
# define WIN_HEIGHT (PAINT_HEIGHT + 24)
# define PI 3.1415926535
# define GREY 0x00535353
# define GREY2 0x00232323
# define GREY3 0x00161616

/*
** Basic Functions
*/

int	my_strlen(char *);
int	my_getnbr(char *);
void	my_putstr(char *);
int	my_printf(const char*, ...);
int	my_strcmp(char *, char *);
char	*my_strcat(char *, char*);
char	*setnbr(int nbr);

/*
** Draw Functions
*/

void	fill_swatch(t_data *);
t_bunny_position	*poser(int, int, t_bunny_position *);
void	square_final(t_data *);
void	invers_color(void *);
void	rond(t_bunny_position *, int, t_data *);
void	draw_pen(void *);
void	draw_lines_left(t_data *, t_bunny_position *);
void	draw_lines_right(t_data *, t_bunny_position *);
int	drag(t_data *data);
int	draw(t_data *data);
void    tekpixel(t_bunny_pixelarray *, t_bunny_position, t_color *);
void    dtekpixel(t_bunny_pixelarray *, t_bunny_position, t_color *);
void    ptekpixel(t_bunny_pixelarray *, t_bunny_position, t_color *);
int	tekline(t_bunny_pixelarray *, t_bunny_position *, t_color *);
void	my_setsquare(t_bunny_pixelarray *, t_posrec, int, int);
void	draw_circle(void *);
void	draw_square(void *);
void	use_bucket(void *);
void	erase(void *);
void	the_pen(void *);
void	the_erase(void *);
void	background(void *);

/*
** Display Functions
*/

void	print_button(void *data);
void	print_calc(void *data);
void	display_button(void *button, t_data *data);
void	display_button_calc(void *calc, t_data *data);
void	set_bg(t_bunny_pixelarray *, unsigned int);
void	display_it(t_data *data, t_bunny_pixelarray *pix, int x, int y);
void	display_text(t_data *data, char *str, int x, int y);
void	display_pos(t_data *data);

/*
** Other Functions
*/

int			calc_is_select(const void* a);
void			replace_draw_area(t_data *data);
int			init_main_variables(t_data *data);
int			init_button(t_data *data);
int			init_all_pixarray(t_data *data);
void			delete_all_clipables(t_data *data);
void			check_action_button(void *button, t_data *data);
int			start(t_data *);
t_bunny_pixelarray	*shade_of_grey(t_bunny_pixelarray *);
t_button		*create_button(t_bunny_pixelarray *pix,
				       t_bunny_position pos, const char* linke);
t_calc			*create_calc(t_data *data, const char* first_name);
void			dtraverse(list *llist, list_op2 do_func, t_data *);
void			say(t_bunny_picture *font, t_bunny_buffer *pic,
			    const t_bunny_position *p, const char *str);
void			disable(void *data);
void			check_button_calc(void *calc, t_data *data);
void			free_calc(void *data);
void			set_max_heap_size(size_t);
void			set_nbr_calc(void* calc, t_data *data);
t_bunny_position	*poser(int x, int y, t_bunny_position *pos);
void			set_color_tool(t_data *data);
unsigned int		getpixelcolor(t_bunny_pixelarray *array,
			       t_bunny_position *pos);
t_color			*get_color(t_data *data, int x, int y);
void		add_calc(void *calci, t_data *data);
void		swap_up(t_calc *calc);
void		get_line_init(void *);
void		get_line_final(void *);
void		draw_line(void *);
void		draw_final_line(void *);

#endif /* !PAINT_H_ */
