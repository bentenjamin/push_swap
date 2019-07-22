#include "ps.h"
// fix main

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
    while (*stck)
    {
        ft_putnbr((*stck)->num);
        *stck = (*stck)->xt;
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
    t_ps    *prevnode;

    prevnode = NULL;
    while (*stck)
    {
        prevnode = *stck;
        *stck = (*stck)->xt;
    }
    if (!(*stck = (t_ps *)malloc(sizeof(t_ps))))
        return (0);
    (*stck)->num = num;
    (*stck)->xt = NULL;
    if (prevnode)
        prevnode->xt = *stck;
    return (1);
}

void    ft_abrt()
{
    
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
        else if ((!(ft_isonly(arr[i], ft_isdigit))) || (ft_atol(arr[i]) > \
                INT32_MAX) || (!(ft_stkadd(ft_atoi(arr[i]), stka))))
            return (0);
    i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_flgs  *flgs;
    t_ps    *stka;

    if (argc == 1)
        exit(0);
    flgs = (t_flgs *)malloc(sizeof(t_flgs));
    if (!(ft_rd(++argv, &stka, &flgs)))
    {
        ft_putstr_fd("Error\n", 2);
        exit(1);
    }
    ft_vstk(&stka);
    ft_freestck(&stka);
}