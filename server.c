/*
** server.c for Server part of minitalk in /u/epitech_2012/vray_s/cu/rendu/c/minitalk
** 
** Made by sebastien vray
** Login   <vray_s@epitech.net>
** 
** Started on  Wed Jan  9 12:01:19 2008 sebastien vray
Last update Tue Jan 29 13:23:34 2008 tisiph0n3
*/
#include "minitalk.h"

void			catch_char(int sig)
{
  static int		i;
  static unsigned char	c;

  if (sig == SIGUSR1 && i != 8)
    {
      c = c | (0 << i);
      printf("0");
      i++;
    } 
  else if (sig == SIGUSR2 && i != 8)
    {
      c = c | (1 << i);
      printf("1");
      i++;
    }
  if (i == 8)
    {
      write(1, &c, 1);
      c = 0;
      i = 0;
    }
}

int	main()
{
  my_putstr("Server pid is: ");
  my_put_nbr(getpid());
  my_putstr("\n");
  while (1)
    {
      signal(SIGUSR1, catch_char);
      signal(SIGUSR2, catch_char);
      pause();
    }
  return (0);
}
