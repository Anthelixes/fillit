#include <string.h>
#include "libft.h"
#include "fillit.h"

int     rezolva_cmmp(t_cmmp *cmmp, t_list *list)
{
    int     x;
    int     y;
    t_piesa *piesa;

    if (list == NULL)
        return (1);
    y = 0;
    piesa = (t_piesa*)(list->content);
    while (y < cmmp->size - piesa->height + 1)
    {
        x = 0;
        while (x < cmmp->size - piesa->width + 1)
        {
            if (verifica_loc(piesa, cmmp, x, y))
            {
                if (rezolva_cmmp(cmmp, list->next))
                    return (1);
                else
                    pune_piesa(piesa, cmmp, punct_nou(x, y), '.');
            }
            x++;
        }
        y++;
    }
    return (0);
}

int     radical(int n)
{
    int size;

    size = 2;
    while (size * size < 2)
        size++;
    return (size);
}

t_cmmp  *rezolva(t_list *list)
{
    t_cmmp *cmmp;
    int     size;
    
    size = radical(ft_lstcount(list) * 4);
    cmmp = creeaza_cmmp(size);
    while (!rezolva_cmmp(cmmp, list))
    {
        size++;
        elibereaza_cmmp(cmmp);
        cmmp = creeaza_cmmp(size);
    }
    return (cmmp);
}