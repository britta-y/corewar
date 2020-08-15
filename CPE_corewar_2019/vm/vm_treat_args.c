/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_treat_args
*/

#include <vm.h>

static void	my_init_param(t_process *process)
{
    int		i;

    i = -1;
    while (++i < 3)
        process->param[i] = 0;
    i = -1;
    while (++i < 3)
        process->param_type[i] = 0;
}

int			my_get_champ_nb(int nb_next_process, t_list *processes)
{
    t_list		*begin_list;
    t_process	*current_process;
    int			nb;
    int			ok;

    nb = -1;
    begin_list = processes;
    if (nb_next_process == -1)
        while (1)
        {
            ok = 1;
            processes = begin_list;
            while (processes)
            {
                current_process = processes->content;
                if (current_process->reg[0] == nb)
                    ok = 0;
                processes = processes->next;
            }
            if (ok == 1)
                return (nb);
            nb--;
        }
    return (nb_next_process);
}

static void	my_get_process(t_list **processes, char *arg, int nb_next_process,
                            t_vm *vm)
{
    t_list			*current;
    t_list			*champ;

    if ((current = (t_list *)malloc(sizeof(t_list))) &&
        (champ = (t_list *)malloc(sizeof(t_list))) &&
        (champ->content = (t_process *)malloc(sizeof(t_process))))
    {
        if ((current->content = my_parse_process(arg, nb_next_process, vm, 0)))
        {
            my_memcpy(champ->content, current->content, sizeof(t_process));
            champ->next = NULL;
            current->content_size = sizeof(t_process);
            ((t_process *)(current->content))->cycles_wo_live = 0;
            my_init_param(current->content);
            current->next = NULL;
            my_lstadd(&vm->champions, champ);
            my_lstadd(processes, current);
        }
    }
    else
        my_exit_malloc_error();
}

int			my_get_opt(t_vm *vm, char *av, int nb_next_process)
{
    int		i;

    i = 0;
    while (av[++i])
    {
        if (av[i] == 'a')
            vm->aff = 1;
        else if (av[i] == 'v')
            vm->verbose = 1;
        else if (av[i] == 'G')
            vm->color = 1;
        else
            my_get_process(&vm->processes, av, nb_next_process, vm);
    }
    return (-1);
}

int			my_treat_args(int ac, char **av, t_vm *vm)
{
    int				i;
    int				nb_next_process;

    i = 0;
    nb_next_process = -1;
    while (++i < ac && vm->nb_champ <= 4)
        if (!my_strcmp(av[i], "-dump") && i++ && my_strisint(av[i]))
            vm->dump = my_atoi(av[i]);
        else if (!my_strcmp(av[i], "-n") && i++ && my_strisint(av[i]))
            nb_next_process = my_atoi(av[i]);
        else if (av[i][0] == '-')
            nb_next_process = my_get_opt(vm, av[i], nb_next_process);
        else if (vm->nb_champ++ || 1)
        {
            my_get_process(&vm->processes, av[i], nb_next_process, vm);
            nb_next_process = -1;
        }
    my_last_check_champ(vm);
    return (1);
}