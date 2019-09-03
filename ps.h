#ifndef PS_H
# define PS_H
# include "Libft/libft.h"
# include <math.h>
# define erexit {ft_putstr_fd("Error\n", 2);exit(1);}
# define vstk(ta, tb, f) {if (f->v) {system("clear");\
                    ft_putendl("\nStack A\t\tStack B");\
                    vall(ta, tb);\
                    ft_putstr("\n\n");\
                    usleep(10000);}}
# define inst(sins, ta, tb, f) {caller(sins, ta, tb);\
                    ft_putendl(sins);\
                    vstk(*ta, *tb, f);}
extern int count;

typedef struct  s_ps
{
    int             dx;
    int             num;
    struct s_ps    *xt;
}                   t_ps;

typedef struct  s_flgs
{
    int             g;
    char            v : 1;
    char            c : 1;
}                   t_flgs;

typedef struct  s_pass
{
    int             x;
    int             y;
    int             num;
    char            **ins;
}                   t_pass;

void                caller(char *s, t_ps **stka, t_ps **stkb);
void                ft_freestck(t_ps **stck);
void                vall(t_ps *ta, t_ps *tb);
void                ft_initflgs(t_flgs **flgs);
int                 ft_setflgs(char *s, t_flgs **flgs, int gps);
int                 ft_stkadd(int num, t_ps **stck);
char                ft_chkdups(int num, t_ps **stk);
int                 ft_rd(char **arr, t_ps **stka, t_flgs **flgs);
int                 shitsort(t_ps **stka, t_ps **stkb, t_flgs **flgs);
char                chkstk(t_ps *stka, t_ps *stkb);
int                 dex(t_ps **stk);
void                printndx(t_ps *stk);
int                 stksize(t_ps *stk);
int                 gsort(t_ps **stka, t_ps **stkb, t_flgs **flgs, int size);

#endif