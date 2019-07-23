#include "ps.h"

void    swp(t_ps **stk)
{
    int i;

    i = (*stk)->num;
    (*stk)->num = (*stk)->xt->num;
    (*stk)->xt->num = i;
}

void    psh(t_ps **stkfrm, t_ps **stkto)
{
    t_ps *tmp;

    tmp = *stkto;
    *stkto = *stkfrm;
    *stkfrm = (*stkfrm)->xt;
    (*stkto)->xt = tmp;
}

void    rot(t_ps **stk)
{
    t_ps    *tmp;

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

    tmp = *stk;
    while (tmp->xt->xt)
        tmp = tmp->xt;
    tmp->xt->xt = *stk;
    *stk = tmp->xt;
    tmp->xt = NULL;
}