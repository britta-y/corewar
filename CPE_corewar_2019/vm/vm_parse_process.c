/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm_parse_process
*/

#include <vm.h>
#include <fcntl.h>

static void		my_parse_process_get_prog(t_process **process, int fd)
{
    char	verif_end[1];

    my_bzero((*process)->prog, MEM_SIZE/6);
    if (read(fd, (*process)->prog, (*process)->header.prog_size + 4) !=
        (*process)->header.prog_size || read(fd, verif_end, 1) != 0)
    {
        free(*process);
        my_exit_msg("INVALID FORMAT (ERROR 0x03 PROG_SIZE DOES NOT MATCH)");
    }
}

static void		my_parse_process_prog_size(t_process **process, int fd)
{
    unsigned int	prog_size;
    unsigned char	current_byte;

    read(fd, &current_byte, 1);
    prog_size = current_byte << 24;
    read(fd, &current_byte, 1);
    prog_size += current_byte << 16;
    read(fd, &current_byte, 1);
    prog_size += current_byte << 8;
    read(fd, &current_byte, 1);
    prog_size += current_byte;
    if (prog_size > MEM_SIZE/6)
    {
        free((*process));
        my_exit_msg("INVALID FORMAT (ERROR 0x03 PROG_SIZE)");
    }
    (*process)->header.prog_size = prog_size;
}

static void		my_parse_process_part_two(t_process **process, int fd)
{
    if (read(fd, (*process)->header.prog_name, 128) != 128)
    {
        free(*process);
        my_exit_msg("INVALID FORMAT (ERROR 0x02 NAME)");
    }
    lseek(fd, 4, SEEK_CUR);
    my_parse_process_prog_size(process, fd);
    if (read(fd, (*process)->header.comment, 2048) != 2048)
    {
        free(*process);
        my_exit_msg("INVALID FORMAT (ERROR 0x04 COMMENT)");
    }
    lseek(fd, 4, SEEK_CUR);
}

static void		my_parse_process_magic_number(t_process **process, int fd,
    char *cor_file_name)
{
    unsigned int	magic;
    unsigned char	current_byte;

    if (read(fd, &current_byte, 1) == -1)
        my_exit_msg(my_sprintf("Can't read source file %s", cor_file_name));
    magic = current_byte << 24;
    read(fd, &current_byte, 1);
    magic += current_byte << 16;
    read(fd, &current_byte, 1);
    magic += current_byte << 8;
    read(fd, &current_byte, 1);
    magic += current_byte;
    if (magic != COREWAR_EXEC_MAGIC)
    {
        free((*process));
        my_exit_msg("INVALID FORMAT (ERROR 0x01 MAGIC NUMBER)");
    }
    (*process)->header.magic = magic;
}

t_process		*my_parse_process(char *cor_file_name, int nb_next_process,
                                    t_vm *vm, int i)
{
    int			fd;
    t_process	*process;
    static int	nb_champ;

    if ((process = (t_process *)malloc(sizeof(t_process))))
    {
        if ((fd = open(cor_file_name, O_RDONLY)) != -1)
        {
            process->reg[0] = my_get_champ_nb(nb_next_process, vm->processes);
            my_init_process(process);
            process->color = nb_champ;
            process->id = nb_champ++;
            while (++i < 16)
                process->reg[i] = 0;
            my_parse_process_magic_number(&process, fd, cor_file_name);
            my_parse_process_part_two(&process, fd);
            my_parse_process_get_prog(&process, fd);
            process->instruction = -1;
        }
        else
            my_exit_msg(my_sprintf("Can't read source file %s", cor_file_name));
    }
    else
        my_exit_malloc_error();
    return (process);
}