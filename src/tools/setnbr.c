/*
** setnbr.c for SETNBR in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Jan 22 05:11:57 2016 bougon_p
** Last update Wed Jan 27 08:13:18 2016 bougon_p
*/

#include "paint.h"

char	*cleanstr(char *nbr)
{
  char	*clean;
  int	p;
  int	i;

  if ((clean = bunny_malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  p = 0;
  while (nbr[p] != 0 && nbr[p++] == '0');
  i = 0;
  p--;
  while (nbr[p] != 0)
    clean[i++] = nbr[p++];
  bunny_free(nbr);
  return (clean);
}

char	*setnbr(int nbr)
{
  char	*numb;
  int	i;
  int	p;

  p = 10;
  if ((numb = bunny_malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  numb[9] = 0;
  i = 0;
  while (p >= 0)
    numb[p--] = ((nbr / (int)(pow(10, i++)) % 10) + '0');
  return (cleanstr(numb));
}
