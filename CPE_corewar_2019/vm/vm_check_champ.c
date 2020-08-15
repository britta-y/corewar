/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_check_champ
*/

#include <vm.h>

int			my_check_champ_numb(t_vm *vm)
{
    t_list	*champs;
    char	check[vm->nb_champ];
    int		i;
    int		j;

    i = -1;
    while (++i < vm->nb_champ)
        check[i] = 0;
    champs = vm->champions;
    i = 0;
    while (champs)
    {
        check[i] = ((t_process*)(champs->content))->id_champ;
        champs = champs->next;
        i++;
    }
    i = -1;
    while (++i < vm->nb_champ)
    {
        j = -1;
        while (++j < vm->nb_champ)
            if (j != i && check[i] == check[j])
                return (1);
    }
    return (0);
}

void		my_last_check_champ(t_vm *vm)
{
    if (vm->nb_champ > 4)
        my_exit_msg("Too many champions");
    if (my_check_champ_numb(vm))
        my_exit_msg("Two champions with the same number");
}