/*
** get_next_line.c for GetNextLine in /home/theis_p/Getnextline
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov 20 18:44:03 2015 Paul THEIS
** Last update Fri Jan  8 13:57:28 2016 Paul THEIS
*/

#include "my.h"

static char     *add_to_line(char *line, int flag, char *buff, int *start)
{
  char          *newlen;
  int           oldlen;

  oldlen = line != 0 ? my_strlen(line) : 0;
  if ((newlen = malloc((oldlen + flag + 1) * sizeof(char))) == NULL)
    return (NULL);
  line != 0 ? my_strncpy(newlen, line, oldlen) : my_strncpy(newlen, "", oldlen);
  newlen[flag + oldlen] = 0;
  my_strncpy(newlen + oldlen, buff + *start, flag);
  if (line)
    free(line);
  *start += flag + 1;
  return (newlen);
}

char            *get_next_line(const int fd)
{
  static char   buff[READ_SIZE];
  static int    nbread;
  static int    start;
  char          *line;
  int           flag;

  line = 0;
  flag = 0;
  nbread = 0;
  while (1)
    {
      if (nbread <= start)
        {
          start = 0;
          if (!(nbread = read(fd, buff, READ_SIZE)))
            return (line);
          if (nbread == -1)
            return (NULL);
          flag = 0;
        }
      if (buff[start + flag] == '\n')
        return (line = add_to_line(line, flag, buff, &start));
      if (start + flag == nbread - 1)
        line = add_to_line(line, flag + 1, buff, &start);
      ++flag;
    }
}
