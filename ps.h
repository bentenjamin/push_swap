#ifndef PS_H
# define PS_H
# include "Libft/libft.h"

# define erexit {ft_putstr_fd("Error\n", 2);exit(1);}
# define vstk(ta, tb, f) {if (f->v) {system("clear");\
                    ft_putendl("\nStack A\t\tStack B");\
                    vall(ta, tb);\
                    ft_putstr("\n\n");\
                    usleep(100000);}}

typedef struct  s_ps
{
    int             num;
    struct s_ps    *xt;
}                   t_ps;

typedef struct  s_flgs
{
    char            v : 1;
    char            c : 1;
}                   t_flgs;

void                caller(char *s, t_ps **stka, t_ps **stkb);
void                ft_freestck(t_ps **stck);
void                vall(t_ps *ta, t_ps *tb);
void                ft_initflgs(t_flgs **flgs);
void                ft_setflgs(char *s, t_flgs **flgs);
int                 ft_stkadd(int num, t_ps **stck);
char                ft_chkdups(int num, t_ps **stk);
int                 ft_rd(char **arr, t_ps **stka, t_flgs **flgs);
int                 sortstk(t_ps **stka, t_ps **stkb, t_flgs **flgs);
char                chkstk(t_ps *stka, t_ps *stkb);

#endif