#include "ps.h"

void    ft_freestck(t_ps **stck)
{
    if (*stck)
    {
        if ((*stck)->xt != NULL)
            ft_freestck(&((*stck)->xt));
        free(*stck);
    }
}

void    vall(t_ps *ta, t_ps *tb)
{
    (ta) ? ft_putnbr(ta->num) : ft_putchar('-');
    ft_putchar('\t');
    (tb) ? ft_putnbr(tb->num) : ft_putchar('-');
    ft_putchar('\n');
    ta = (ta) ? ((ta->xt) ? ta->xt : NULL) : NULL;
    tb = (tb) ? ((tb->xt) ? tb->xt : NULL) : NULL;
    if (ta || tb)
        vall(ta, tb);
}

void    ft_initflgs(t_flgs **flgs)
{
    (*flgs)->c = 0;
    (*flgs)->v = 0;
}

void    ft_setflgs(char *s, t_flgs **flgs)
{
    int i;

    i = 0;
    while (s[++i])
        if (s[i] == 'c')
            (*flgs)->c = 1;
        else if (s[i] == 'v')
            (*flgs)->v = 1;
}

int ft_stkadd(int num, t_ps **stck)
{
    t_ps    *nd;
    t_ps    *prevnode;

    nd = *stck;
    prevnode = NULL;
    while (nd)
    {
        prevnode = nd;
        nd = nd->xt;
    }
    if (!(nd = (t_ps *)malloc(sizeof(t_ps))))
        return (0);
    nd->num = num;
    nd->xt = NULL;
    if (!*stck)
        *stck = nd;
    if (prevnode)
        prevnode->xt = nd;
    return (1);
}

char    ft_chkdups(int num, t_ps **stk)
{
    if (*stk)
    {
        if (num == (*stk)->num)
            return (1);
        if (!((*stk)->xt))
            return (0);
        return(ft_chkdups(num, &((*stk)->xt)));
    }
    return (0);
}

int ft_rd(char **arr, t_ps **stka, t_flgs **flgs)
{
    int     i;
    int     k;
    char    **splt;

    i = 0;
    while (arr[i])
    {
        if (ft_strchr(arr[i], ' '))
        {
            k = 0;
            splt = ft_strsplit(arr[i], ' ');
            ft_rd(splt, stka, flgs);
            while (splt[k])
                free(splt[k++]);
            free(splt);
        }
        else if (arr[i][0] == '-')
            ft_setflgs(arr[i], flgs);
        else if ((!(ft_isonly(arr[i], ft_isdigit))) || \
                (ft_atol(arr[i]) > INT32_MAX) || \
                ft_chkdups(ft_atoi(arr[i]), stka) || \
                (!(ft_stkadd(ft_atoi(arr[i]), stka))))
            return (0);
    i++;
    }
    return (1);
}