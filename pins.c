#include "ps.h"

int    swp(t_ps **stk)
{
    int i;

    if (!(*stk) || !((*stk)->xt))
        return (0);
    i = (*stk)->num;
    (*stk)->num = (*stk)->xt->num;
    (*stk)->xt->num = i;
    return (1);
}

int    psh(t_ps **stkfrm, t_ps **stkto)
{
    t_ps *tmp;

    if (!(*stkfrm))
        return (0);
    tmp = *stkto;
    *stkto = *stkfrm;
    *stkfrm = (*stkfrm)->xt;
    (*stkto)->xt = tmp;
}

int    rot(t_ps **stk)
{
    t_ps    *tmp;

    if (!(*stk) || !((*stk)->xt))
        return (0);
    tmp = *stk;
    while (tmp->xt)
        tmp = tmp->xt;
    tmp->xt = *stk;
    *stk = (*stk)->xt;
    tmp->xt->xt = NULL;
}

int    revrot(t_ps **stk)
{
    t_ps    *tmp;

    if (!(*stk) || !((*stk)->xt))
        return (0);
    tmp = *stk;
    while (tmp->xt->xt)
        tmp = tmp->xt;
    tmp->xt->xt = *stk;
    *stk = tmp->xt;
    tmp->xt = NULL;
}

int    caller(char *s, t_ps **stka, t_ps **stkb)
{
    if (s == "sa" || s == "ss")
        return (swp(stka));
    if (s == "sb" || s == "ss")
        return (swp(stkb));
    if (s == "pa")
        return (psh(stkb, stka));
    if (s == "pb")
        return (psh(stka, stkb));
    if (s == "ra" || s == "rr")
        return (rot(stka));
    if (s == "rb" || s == "rr")
        return (rot(stkb));
    if (s == "rra" || s == "rrr")
        return (revrot(stka));
    if (s == "rrb" || s == "rrr")
        return (revrot(stkb));
    return (0);
}