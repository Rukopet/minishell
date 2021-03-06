#ifndef DNI_STRUCTS_H
# define DNI_STRUCTS_H

typedef struct s_pars
{
	char			*s;
	char			*command;
	char			**envp;
	int				quot_flag;
	int				back_slash;
	int				tmp;
	int				tmp_flag;
	t_bin			*b;
}					t_pars;

// quot flag 1 - " | 2 - '|

typedef struct s_frs
{
	const char	*substr;
	char		*str;
	const char	*rep_str;
	int			*i;
	int			*lim1;
	int			*lim2;
	int			tmp_i;
	int			tmp_j;
}				t_fts;

typedef struct s_hist
{
	int				SHLVL;
	char			*terminal;
	char			*exec_path;
	int				fd_for_add;
	struct termios	*term;
	char			*left;
	char			*right;

	char			**h;
	char			*tmp_line;
	int				h_len;
	int				curr_line;
	int				term_cols;
	int				term_lines;
}					t_hist;

#endif
