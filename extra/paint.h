/*
** paint.h for extra in /home/clemen_j/Work/Infographie/gfx_tekpaint/extra
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Jan 25 20:45:03 2016 Clémenceau Cedric
** Last update Tue Jan 26 22:36:21 2016 Clémenceau Cedric
*/


#ifndef PAINT_H_
# define PAINT_H_

# include "lapin.h"
# include "unistd.h"
# include <sys/stat.h>
# include <fcntl.h>


typedef struct                  s_load
{
  unsigned short int            type;               /* Magic identifier            */
  unsigned int                  size;               /* File size in bytes          */
  unsigned short int            reserved1;
  unsigned short int            reserved2;
  unsigned int                  offset;             /* Offset to image data, bytes */
  unsigned int                  size_pict;               /* Header size in bytes      */
  int                           width;              /* Width and height of image */
  int                           height;
  unsigned short int            planes;             /* Number of colour planes   */
  unsigned short int            bits;               /* Bits per pixel            */
  unsigned int                  compression;        /* Compression type          */
  unsigned int                  imagesize;          /* Image size in bytes       */
  int                           xresolution;        /* Pixels per meter          */
  int                           yresolution;
  unsigned int                  ncolours;           /* Number of colours         */
  unsigned int                  importantcolours;   /* Important colours         */

} __attribute__((packed))       t_load;

typedef struct		s_data
{
  t_bunny_window	*window;
  t_bunny_pixelarray    *image;
  t_load		bmp;
  t_color               col_image[1];
  char			buffer[4];
}			t_data;

void	tekpixel(t_bunny_pixelarray *, t_bunny_position,
		 t_color *);

#endif /* PAINT_H_ */
