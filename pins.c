#include "ps.h"

void    swp(t_ps **stk)
{
    t_ps *t;

    if (!(*stk) || !((*stk)->xt))
        return ;
    t = (*stk)->xt;
    (*stk)->xt = (*stk)->xt->xt;
    t->xt = (*stk);
    *stk = t;
}

void    psh(t_ps **stkfrm, t_ps **stkto)
{
    t_ps *tmp;

    if (!(*stkfrm))
        return ;
    tmp = *stkto;
    *stkto = *stkfrm;
    *stkfrm = (*stkfrm)->xt;
    (*stkto)->xt = tmp;
}

void    rot(t_ps **stk)
{
    t_ps    *tmp;

    if (!(*stk) || !((*stk)->xt))
        return ;
    tmp = *stk;
    while (tmp->xt)
        tmp = tmp->xt;
    tmp->xt = *stk;
    *stk = (*stk)->xt;
    tmp->xt->xt = NULL;
}

void    revrot(t_ps **stk)
{
    t_ps    *tmp;

    if (!(*stk) || !((*stk)->xt))
        return ;
    tmp = *stk;
    while (tmp->xt->xt)
        tmp = tmp->xt;
    tmp->xt->xt = *stk;
    *stk = tmp->xt;
    tmp->xt = NULL;
}

void    caller(char *s, t_ps **stka, t_ps **stkb)
{
    if (ft_strncmp(s,"sa", 2) == 0 || ft_strncmp(s,"ss", 2) == 0)
        swp(stka);
    if (ft_strncmp(s,"sb", 2) == 0 || ft_strncmp(s,"ss", 2) == 0)
        swp(stkb);
    if (ft_strncmp(s,"pa", 2) == 0)
        psh(stkb, stka);
    if (ft_strncmp(s,"pb", 2) == 0)
        psh(stka, stkb);
    if (ft_strncmp(s,"ra", 2) == 0 || ft_strncmp(s,"rr", 2) == 0)
        rot(stka);
    if (ft_strncmp(s,"rb", 2) == 0 || ft_strncmp(s,"rr", 2) == 0)
        rot(stkb);
    if (ft_strncmp(s,"rra", 3) == 0 || ft_strncmp(s,"rrr", 3) == 0)
        revrot(stka);
    if (ft_strncmp(s,"rrb", 3) == 0 || ft_strncmp(s,"rrr", 3) == 0)
        revrot(stkb);
}