#include "ps.h"
/*split a into b where b < a
cocktail sorting
every iteration of sorting going from left to right or right to left is called a pass
call plist to make a list of instructions needed for the pass of a and b with the direction of movement being the same
during a pass there can only 2 instructions can be called, swap or (rot/rrot depending on current pass direction)
read through the plist and count the num of r and s in each
there is a priority on either s or r as to whether the fuction must skip or wait an instruction on the plists in order to use rrr or ss
priority(x) is on highest # of r or s  in the smaller stack(s)
if lx < sx but lx > sy then x = x
if lx < sx but lx < sy then x = y
the function will the execute the plists when a = b else wait on x of a or b until sx && lx then continue
pop lx to equal s until lx = sx
if s and s- == l-- and l-
repeat this every pass until sorted
push b to a*/
void    pshb(t_ps **stka, t_ps **stkb, t_flgs **flgs, int indx)
{
    int i;

    i = 0;
    while (++i <= indx)
    {
        if ((*stka)->dx <= (indx/2))
        {
            caller("pb", stka, stkb);
            vstk((*stka), (*stkb), (*flgs));
        }
        caller("rot", stka, stkb);
        vstk((*stka), (*stkb), (*flgs));
    }
}

void    pfwd(t_ps *stk, t_pass **pdets, int iter)
{
    char    *insts;

    (*pdets)->num = 0;
    insts = "\0";
    while (iter)
    {
        if (stk->num > stk->xt->num)
        {
            caller ("sa", &stk, NULL);
            ft_strcat(insts, "s ");
            (*pdets)->num++;
        }
        caller ("ra", &stk, NULL);
        ft_strcat(insts, "r ");
        (*pdets)->num++;
        iter--;
    }
    (*pdets)->ins = ft_strsplit(insts, ' ');
}

void    prev(t_ps *stk, t_pass **pdets, int iter)
{
    char    *insts;

    (*pdets)->num = 0;
    insts = "\0";
    while (iter)
    {
        caller ("rra", &stk, NULL);
        ft_strcat(insts, "r ");
        (*pdets)->num++;
        iter--;
        if (stk->num > stk->xt->num)
        {
            caller ("sa", &stk, NULL);
            ft_strcat(insts, "s ");
            (*pdets)->num++;
        }
    }
    (*pdets)->ins = ft_strsplit(insts, ' ');
}

int stkcount(t_ps *stk)
{
    int i;

    i = 0;
    while (stk)
    {
        i++;
        stk = stk->xt;
    }
    return(i);
}

int cocksort(t_ps **stka, t_ps **stkb, t_flgs **flgs, int indx)
{
    t_pass  *ap;
    t_pass  *bp;
    char    dir;
    char    *t;

    pshb(stka, stkb, flgs, indx);
    dir = 1;
    while (ia && ib)
    {
    if (ap)
        free(ap);
    if (bp)
        free(bp);
    ap = (t_pass *)malloc(sizeof(t_pass));
    bp = (t_pass *)malloc(sizeof(t_pass));
    if (dir)
    {
        pfwd(*stka, &ap, ia);
        pfwd(*stkb, &bp, ib);
    }
    else
    {
        prev(*stka, &ap, ia);
        prev(*stkb, &bp, ib);
    }
    while (ap->num || bp->num)
    {
        if (ap->ins[ap->num] == bp->ins[bp->num])
        {
            t = (ap->ins[ap->num] == 'r') ? ((dir) ? "rr" : "rrr") : "ss";
            ft_putstr_fd(t, 0);
            caller(t, stka, stkb);
            vstk((*stka), (*stkb), (*flgs));
        }
        else
        {
        if (ap->num > bp->num)
        {
            while ((ap->ins[ap->num] != bp->ins[bp->num]) &&  (ap->num) && (bp->num) && (ap->num > bp->num))
            {
                ft_putstr_fd("sa", 0);
                caller("sa", stka, stkb);
                vstk((*stka), (*stkb), (*flgs));
                ap->num--;
            }
        }
        }
        
    }
    }


}