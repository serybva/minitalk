/*
** bonus.c for bonus of the minitalk (not activated) in /u/epitech_2012/vray_s/cu/rendu/c/minitalk
** 
** Made by sebastien vray
** Login   <vray_s@epitech.net>
** 
** Started on  Wed Jan  9 12:04:35 2008 sebastien vray
** Last update Wed Jan  9 12:04:38 2008 sebastien vray
*/

/*static unsigned int   clientpid;

void            get_clientpid(int sig)
{
  static int    i = 0;

  if (sig == SIGUSR1 && i != 32)
    {
      clientpid = clientpid | (0 << i);
      i++;
    }
    else if (sig == SIGUSR2 && i != 32)
    {
      clientpid = clientpid | (1 << i);
      i++;
    }
    }
static int    checksum;

void            get_checksum(int sig)
{
  static int    i;

  if (sig == SIGUSR1 && i != 32)
    {
      checksum = checksum | (0 << i);
      i++;
    }
  else if (sig == SIGUSR2 && i != 32)
    {
      checksum = checksum | (1 << i);
      i++;
    }
}*/
/*void          send_pid(int servpid)
{
  int           i;
  int           mask;
  unsigned int  pid;

  i = 0;
  mask = 1;
  pid = getpid();
  while (i != 32)
    {
      if (((pid & mask) == mask) && i != 32)
        {
          kill(servpid, SIGUSR2);
          mask *= 2;
          i++;
        }
	else if (((pid & mask) == 0) && i != 32)
        {
          kill(servpid, SIGUSR1);
          mask *= 2;
          i++;
        }
      usleep(1);
    }
}

int     compute_checksum(char *str)
{
  int   i;
  int   sum;

  i = 0;
  sum = 0;
  while (str[i] != '\0')
    {
      sum += str[i];
      i++;
    }
  return (sum);
}

void          send_checksum(int servpid, int checksum)
{
  int           i;
  int           mask;

  i = 0;
  mask = 1;
  while (i != 32)
    {
      if (((checksum & mask) == mask) && i != 32)
        {
          kill(servpid, SIGUSR2);
          mask *= 2;
          i++;
        }
	else if (((checksum & mask) == 0) && i != 32)
        {
          kill(servpid, SIGUSR1);
          mask *= 2;
          i++;
        }
      usleep(1);
    }
}*/
