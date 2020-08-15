/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** vm
*/

#ifndef VM_H
# define VM_H

# include <corewar.h>
# include <locale.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}t_list;

typedef struct		s_vm
{
	void			(*f[16])(struct s_vm *, t_process *);
	t_list			*processes;
	t_list			*champions;
	unsigned char	memory[MEM_SIZE];
	char			mem_color[MEM_SIZE];
	int				dump;
	int				verbose;
	int				nb_champ;
	int				nb_process;
	int				cycle_to_die;
	int				ctd_decrem;
	int				total_cycles;
	int				cycles;
	int				nb_checks;
	int				live;
	int				last_live;
	int				aff;
	int				sleep;
	int				color;
}					t_vm;

# define OPCODE_LIVE	1
# define OPCODE_LD		2
# define OPCODE_ST		3
# define OPCODE_ADD		4
# define OPCODE_SUB		5
# define OPCODE_AND		6
# define OPCODE_OR		7
# define OPCODE_XOR		8
# define OPCODE_ZJMP	9
# define OPCODE_LDI		10
# define OPCODE_STI		11
# define OPCODE_FORK	12
# define OPCODE_LLD		13
# define OPCODE_LLDI	14
# define OPCODE_LFORK	15
# define OPCODE_AFF		16

# define OP_TAB			g_op_tab[(int)process->instruction]

t_process			*my_parse_process(char *cor_file_name, int nb_next_process,
									t_vm *vm, int i);
void				deb_print_process(t_list *processes);
int					my_treat_args(int ac, char **av, t_vm *vm);
int					my_get_champ_nb(int nb_next_process, t_list *processes);
void				my_prepare_memory(t_vm *vm);
void				deb_print_memory(t_vm *vm);
void				my_lstaddchamp(t_list **processes, t_list *process);
void				my_virtual_foam_bat(t_vm *vm, int id);
void				my_handle_process(t_vm *vm, t_process *process);
int					my_launch_vm(t_vm *vm);
void				my_savage_slaughter(t_vm *vm, t_list *prev_process,
						t_list *current_process);
void				my_kill_vm(t_vm *vm);
void				my_init_vm(t_vm *vm);
void				my_init_ncurses(t_vm *vm);
void				my_init_visu(t_vm *vm);
void				init_tab_instruction(t_vm *vm);
int					my_check_champ_numb(t_vm *vm);
int					my_check_param(t_process *process, int i);
int					my_get_ocp(t_vm *vm, t_process *process);
void				my_get_instruction(t_vm *vm, t_process *process);
void				my_last_check_champ(t_vm *vm);

/*
** instructions
*/

void				my_live(t_vm *vm, t_process *process);
void				my_ld(t_vm *vm, t_process *process);
void				my_st(t_vm *vm, t_process *process);
void				my_add(t_vm *vm, t_process *process);
void				my_sub(t_vm *vm, t_process *process);
void				my_and(t_vm *vm, t_process *process);
void				my_or(t_vm *vm, t_process *process);
void				my_xor(t_vm *vm, t_process *process);
void				my_zjmp(t_vm *vm, t_process *process);
void				my_ldi(t_vm *vm, t_process *process);
void				my_sti(t_vm *vm, t_process *process);
void				my_fork(t_vm *vm, t_process *process);
void				my_lld(t_vm *vm, t_process *process);
void				my_lldi(t_vm *vm, t_process *process);
void				my_lfork(t_vm *vm, t_process *process);
void				my_aff(t_vm *vm, t_process *process);
void				my_print_reg(t_process *process, int i);

/*
** utilities
*/

void				my_store(t_vm *vm, t_process *process, int adress);
int					my_load(t_vm *vm, int size, int adress);

/*
** verbose
*/

void				my_adv_invalid(t_process *process, t_vm *vm);
void				my_print_ind(t_vm *vm, t_process *process, int i);
void				my_verbose(t_vm *vm, t_process *process);
void				my_verbose2(t_process *process, t_vm *vm);
void				my_verbose3(t_process *process, t_vm *vm);
int					my_verbose5(t_process *process);
void				my_print_pc(t_vm *vm, t_process *process);
void				my_print_octet(t_vm *vm, int adress);
void				my_erase_pc(t_vm *vm, t_process *process);
void				my_refresh_infos(t_vm *vm);
void				my_init_infos(t_vm *vm);
void				my_apply_ch(t_vm *vm, int ch);
void				my_init_process(t_process *process);
void				my_print_champs_lives(t_list *champ, int line);

#endif
