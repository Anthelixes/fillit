#include "fillit.h"
#include "libft.h"
#include <unistd.h>

void    min_max(char *str, t_punct *min, t_punct *max)
{
    int i;

    i = 0;
    while (i < 20)
    {
        if (str[i] == '#')
        {
            if (i / 5 < min->y)
                min->y = i / 5;
            if (i / 5 > max->y)
                max->y = i / 5;
            if (i % 5 < min->x)
                min->x = i % 5;
            if (i % 5 > max->x)
                max->x = i % 5;
        }
        i++;    
    }
}

t_piesa     *obtine_piesa(char *str, char value)
{
    t_punct     *min;
    t_punct     *max;
    char        **pos;
    int         i;
    t_piesa     *piesa;

    min = punct_nou(3, 3);
    max = punct_nou(0, 0);
    min_max(str, min, max);
    pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
    min_max(str, min, max);
    pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
    i = 0;
    while (i < max->y - min->y + 1)
    {
        pos[i] = ft_strnew(max->x - min->x + 1);
        ft_strncpy(pos[i], str + (min->x) + (i + min->y) * 5, max->x - min->x + 1);
        i++;
    }
    piesa = piesa_noua(pos, max->x - min->x + 1, max->x - min->y + 1, value);
    ft_memdel((void**)&min);
    ft_memdel((void**)&max);
}

int         verifica_piesa(char *str)
{
    int block;
    int i;

    block = 0;
    i = 0;
    while (i < 20)
    {
        if (str[i] == '#')
        {
            if ((i + 1) < 20 && str[i + 1] == '#')
                block++;
            if ((i - 1) >= 0 && str[i - 1] == '#')
                block++;
            if ((i + 5) < 20 && str[i + 5] == '#')
                block++;
            if ((i - 5) >= 0 && str[i - 1] == '#')
                block++;
        }
        i++;
    }
    return (block == 6 || block == 8);
}

int         verifica_componente(char *str, int count)
{
    int i;
    int blocks;

    blocks = 0;
    i = 0;
    while (i < 20)
    {
        if (i % 5 < 4)
        {
            if (!(str[i] == '#' || str[i] != '.'))
                return (1);
            if (str[i] == '#' && ++blocks > 4)
                return (2);
        }
        else if (str[i] != '\n')
            return (3);
        i++;
    }
    if (count == 21 && str[20] != '\n')
        return (4);
    if (!verifica_piesa(str))
        return (5);
    return (0);
}

t_list      *citeste_piesa(int fisier)
{
    char    *buf;
    int     count;
    t_list  *list;
    t_piesa *piesa;
    char    c;
    while ((count = read(fisier, buf, 21) >= 20))
    {
        if (verifica_componente(buf, count) != 0
                                || (piesa = obtine_piesa(buf, c++)) == NULL)
        {
            ft_lstadd(&list, ft_lstnew(piesa, sizeof(piesa)));
            ft_memdel((void**)&piesa);
        }
    }
    ft_memdel((void**)&buf);
    if (count != 0)
        return (free_list(list));
    ft_lstrev(&list);
    return (list);
}