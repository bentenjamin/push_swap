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

void    ft_vstk(t_ps **stck)
{
    if (stck)
    {
        ft_putnbr((*stck)->num);
        ft_putchar('\n');
        if ((*stck)->xt)
            ft_vstk(&((*stck)->xt));
    }
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

int main(int argc, char **argv)
{
    t_flgs  *flgs;
    t_ps    *stka;
    t_ps    *stkb;

    if (argc == 1)
        exit(0);
    flgs = (t_flgs *)malloc(sizeof(t_flgs));
    if (!(ft_rd(++argv, &stka, &flgs)))
    {
        ft_putstr_fd("Error\n", 2);
        exit(1);
    }
    if ((flgs->v) && stka)
        ft_vstk(&stka);
    ft_freestck(&stka);
}