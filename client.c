/*
** client.c for client part of minitalk in /u/epitech_2012/vray_s/cu/rendu/c/minitalk
** 
** Made by sebastien vray
** Login   <vray_s@epitech.net>
** 
** Started on  Wed Jan  9 12:01:55 2008 sebastien vray
Last update Tue Jan 29 13:26:39 2008 tisiph0n3
*/
#include "minitalk.h"

void	send_char(int servpid, char c)
{
  int	i;
  int	mask;

  i = 0;
  mask = 1;
  while (i != 8)
    {
      if ((c & mask) == mask)
	{
	  if (kill(servpid, SIGUSR2)== -1)
	    {
	      my_putstr("This pid doesn't appear to be the correct one\n");
	      exit(0);
	    }
	  mask *= 2;
	  i++;
	}
      else if ((c & mask) == 0)
	{
	  if (kill(servpid, SIGUSR1) == -1)
	    {
	      my_putstr("This pid doesn't appear to be the correct one\n");
	      exit(0);
	    }
	  mask *= 2;
	  i++;
	}
    }
} 

void	send_str(int servpid, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      send_char(servpid, str[i]);
      i++;
      usleep(1);
    }
}

int	check_param(int argc, char *str)
{
  int   i;

  i = 0;
  if (argc < 3)
    {
      my_putstr("Too few arguments:\n");
      my_putstr("Usage: [server pid] [string] [...]\n");
      return (1);
    }
  if (my_strlen(str) > 6)
    {
      my_putstr("Do you really think a pid is so huge?\n");
      return (1);
    }
  while(str[i] != '\0')
    {
      if (str[i] > '9' || str[i] < '0')
        {
          my_putstr("Server pid must be a number\n");
          my_putstr("Usage: [server pid] [string] [...]\n");
          return (1);
        }
      i++;
    }
  return (0);
}

int	main(int argc, char **argv)
{
  int	i;
  int	servpid;

  if (check_param(argc, argv[1]) == 1)
    return(1);
  servpid = my_getnbr(argv[1]);
  i = 2;
  while (i != argc)
    {
      send_str(servpid, argv[i]);
      i++;
    }
  return (0);
}
