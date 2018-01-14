#include <fcntl.h>
#include "libft.h"
#include "fillit.h"

int main(int argc, char **argv)
{
    t_list  *list;
    t_map   *cmmp;

    if (argc != 2)
    {
        ft_putstr("usage: fillit input_file\n");
        return (1);
    }
    if ((list = citeste_tetris(open(argv[1], O_RDONLY))) == NULL))
    {
        ft_putstr("error\n");
        return (1);
    }
    cmmp = rezolva(list);
    afiseaza_cmmp(cmmp);
    elibereaza_cmmp(cmmp);
    elibereaza_lista(list);
    return (0);
}