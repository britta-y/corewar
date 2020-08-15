/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 17:04:30 by lgosse            #+#    #+#             */
/*   Updated: 2016/09/17 17:52:29 by gbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <../lib/my/my.h>
# include <op.h>

extern op_t				g_op_tab[];
typedef char			t_arg_type;

typedef struct		s_process
{
	header_t		header;
	int				color;
	int				id;
	int				id_champ;
	int				reg[REG_NUMBER];
	int				pc;
	int				pc2;
	int				carry;
	int				cycle_bf_exe;
	int				cycles_wo_live;
	int				param[3];
	t_arg_type		param_type[3];
	char			instruction;
	int				ocp;
	unsigned char	prog[MEM_SIZE/6];
	int				nb_live;
}					t_process;

#endif
