#ifndef PRE_PARSING_H
# define PRE_PARSING_H

int pre_pars_branching(char *envp[], t_pars *pa);
int 			check_char(char *cur_arg, t_pars *pa);
int				check_spaces_prep(char *cur_arg, t_pars *pa);

int check_chars_subst(char **arg, t_pars *pa, int *i);
char			*copy_new_prepars_str(char *arg);

int 		del_env_arg(char **arg, char *str, int *i, t_pars *pa);
char		*take_arg_from_env(char **arg, char *str, int *i, t_pars *pa);


#endif
