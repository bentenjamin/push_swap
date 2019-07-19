#ifndef PS_H
# define PS_H
# include "Libft/libft.h"

typedef struct  s_ps
{
    int     num;
    char    *xt;
}           t_ps;

typedef struct  s_flgs
{
    char    v : 1;
    char    c : 1;
}           t_flgs;

#endif