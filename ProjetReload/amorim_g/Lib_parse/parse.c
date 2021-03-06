/*
** my_strcmp.c for my_strcmp in /home/amorim_g/semaine03/amorim_g/libmy_02
**
** Made by AMORIM Greg
** Login   <amorim_g@etna-alternance.net>
**
** Started on  Mon Oct 27 13:01:06 2014 AMORIM Greg
** Last update Wed Oct 29 11:41:02 2014 AMORIM Greg
*/

#include "parse.h"

void  display_args(t_arg *list)
{
  t_arg	*tmp;
  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->option);
      my_putstr("\n");
      my_putstr(tmp->argument);
      my_putstr("\n");
      tmp = tmp->suivant;
    }
}

t_arg		*parsing(int argc,char *argv[],t_option *opt)
{
  t_option	*temp;
  t_arg		*arg;
  int		i;
    
  arg = NULL;
  for (temp = opt; temp != NULL; temp = temp->suivant)
   {
     for (i = 1; i < argc; i++)
     {
       if (my_strcmp(argv[i], temp->option) == 0)
       {
         if (((i + 1) < argc)  && (!args_and_opts(opt, argv[i + 1])))
         {
           i++;
           arg = argument_add(arg, temp, argv[i]);
         }
       }
     }
   }
  return (arg);
}

void    display_opts(t_option *list)
{
  t_option  *tmp;
  tmp = list;
    
  while (tmp != NULL)
   {
     my_putstr(tmp->option);
     tmp = tmp->suivant;
     my_putstr("\n");
   }
}

int		args_and_opts(t_option *opt, char *valeur)
{
  t_option	*tmp;
  
  tmp = opt;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->option, valeur) == 0)
       {
          return (1);
       }
      tmp = tmp->suivant;
    }
  return (0);
}

