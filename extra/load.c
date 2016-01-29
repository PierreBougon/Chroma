/*
** load.c for tekpaint in /home/clemen_j/Work/Infographie/gfx_tekpaint
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Jan 25 15:27:11 2016 Clémenceau Cedric
** Last update Tue Jan 26 23:33:39 2016 Clémenceau Cedric
*/

#include "paint.h"

void	col_tek(t_data *data)
{
  data->col_image[0].argb[0] = data->buffer[2];
  data->col_image[0].argb[1] = data->buffer[1];
  data->col_image[0].argb[2] = data->buffer[0];
  data->col_image[0].argb[3] = data->buffer[3];
}

t_bunny_pixelarray	*load_bmp(t_data *data, const char *name)
{
  int			fd;
  int			readed;
  t_bunny_position	pos;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (NULL);
  if ((readed = read(fd, &data->bmp, 54)) == -1)
    return (NULL);
  data->image = bunny_new_pixelarray(data->bmp.width, data->bmp.height);
  pos.y = data->bmp.height - 1;
  while (pos.y != -1)
    {
      pos.x = 0;
      while (readed > 0 && pos.x != data->bmp.width)
	{
	  pos.x += 1;
	  if ((read(fd, data->buffer, (data->bmp.bits / 8))) == -1)
	    return (NULL);
	  col_tek(data);
	  tekpixel(data->image, pos, data->col_image);
	}
      pos.y--;
    }
  return (data->image);
}

t_bunny_response	main_loop(void *_data)
{
  t_data		*data;

  data = _data;
  bunny_blit(&data->window->buffer, &data->image->clipable,0);
  bunny_display(data->window);
  return (GO_ON);
}

int	main(int ac, char **av)
{
  t_data		data;

  ac = ac;
  if ((data.image = load_bmp(&data, av[1])) == NULL)
    return (1);
  data.window = bunny_start(data.bmp.width, data.bmp.height, 0, "load_functions, It Woks Well");
  bunny_set_loop_main_function(main_loop);
  bunny_loop(data.window, 60, &data);
  return (0);
}
