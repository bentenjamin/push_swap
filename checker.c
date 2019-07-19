#include "ps.h"
//write atol, stkadd. fix main
int main(int argc, char **argv)
{
    t_flgs  flgs;
    t_ps    stka;
    int i;

    if (argc == 1)
        exit(0);
    args = chkargs()
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

int ft_rd(char **arr, t_ps **stka, t_flgs **flgs)
{
    int     i;

    i = 0;
    while (arr[i])
    {
        if (ft_strchr(arr[i], ' '))
            ft_rd(ft_strsplit(arr[i], ' '), stka, flgs);
        else if (arr[i][0] == '-')
            ft_setflgs(arr[i], flgs);
        else if (!(ft_isonly(arr[i], ft_isdigit)))
            ft_abt;
        else if (ft_atol(arr[i]) > INT32_MAX)
            ft_abt;
        else
            ft_stkadd(ft_atoi(arr[i]), stka);
    i++;
    }
}

void    ft_abt()
{
    ft_putstr_fd("Error\n", 2);
    exit(1);
}