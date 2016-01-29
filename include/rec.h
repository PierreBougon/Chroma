/*
** rec.h for REC in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Jan  8 03:27:19 2016 bougon_p
** Last update Mon Jan 18 05:04:56 2016 bougon_p
*/

#ifndef REC_H_
# define REC_H_
# include "lapin.h"

typedef struct  s_posline
{
  float         coef;
  int           b;
  int           i;
  t_color       color;
}               t_posline;

typedef struct  s_posrec
{
  int           x;
  int           y;
  t_color       color;
}		t_posrec;

#endif /* !REC_H_ */
