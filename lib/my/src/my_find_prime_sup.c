/*
** my_find_prime.c for my_find_prime.c in /home/theis_p/git/Piscine_C_J05
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Oct  2 11:11:32 2015 Paul THEIS
** Last update Fri Oct  2 11:29:08 2015 Paul THEIS
*/

#include "./my.h"

int     my_find_prime_sup(int nb)
{
  int   resultat;

  resultat = my_is_prime(nb);
  while (resultat == 0)
    {
      nb = nb + 1;
      resultat = my_is_prime(nb);
    }
  return (nb);
}
