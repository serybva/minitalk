#ifndef __MY__
#define __MY__
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int	my_strlen(char *str);
int	my_put_nbr(int nb);
int	my_getnbr(char *str);
void    my_putnbr_base(int n, char *base);
int	my_putstr(char *str);
#endif
