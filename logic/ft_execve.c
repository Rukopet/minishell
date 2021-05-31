#include "header.h"

int	check_error_in_get_execve_str(t_bin *bin, char *command, char **argv)
{
	null_ceiges(bin);
	if (!command || !argv)
		return (0);
	if (command[ft_strlen(command) - 1] == '/')
	{
		bin->folder = opendir(command);
		if (bin->folder)
			bin->dirent = readdir(bin->folder);
		if (command)
			command_error(command, 6);
		else
			command_error(command, 5);
		return (-1);
	}
	if (argv[0][0] == '/' || argv[0][0] == '.')
	{
		bin->execve_str = ft_strdup(command);
		return (1);
	}
	return (0);
}

int	check_dirent(t_bin *bin, char *command)
{
	if (!bin->dirent)
	{
		if (bin->split_str)
		{
			free_split(bin->split_str);
			bin->split_str = NULL;
		}
		command_error(command, 1);
		return (-1);
	}
	bin->execve_str = ft_strjoin(bin->dir_to_open, command);
	free_diropen(bin);
	return (0);
}

void	body_get_excve_str_cycle(t_bin *bin, int *ret, int *flag, char *command)
{
	if (!command)
		return ;
	bin->dirent = readdir(bin->folder);
	if (!bin->dirent)
		*ret = 0;
	if (bin->dirent && !strcmp(bin->dirent->d_name, command))
		*flag = 0;
}

char	*get_excve_str(t_bin *bin, char *command, char **argv)
{
	int				ret;
	int				flag;
	int				i;

	i = 0;
	flag = 1;
	if (!check_error_in_get_execve_str(bin, command, argv))
	{
		if (make_path_str(bin, command) == -1)
			return (NULL);
		while (bin->split_str[i] && flag)
		{
			free_and_write_get_execve_str(bin, i);
			while (bin->folder && ret && flag)
				body_get_excve_str_cycle(bin, &ret, &flag, command);
			ret = 1;
			if (bin->folder)
				closedir(bin->folder);
			bin->folder = NULL;
			i++;
		}
		if (check_dirent(bin, command) == -1)
			return (NULL);
	}
	return (ret_get_excve_str(bin));
}

void	ft_execve(t_bin *bin, char *execve_str, char **argv, int status)
{
	execve_str = get_excve_str(bin, argv[0], argv);
	if (execve_str)
		bin->pid = fork();
	if (bin->pid == 0)
	{
		g_sig.exit_status = execve(execve_str, argv, bin->envp);
		excve_exit_errno(execve_str);
		free(execve_str);
		exit(0);
	}
	else
	{
		waitpid(bin->pid, &status, 0);
		ft_close_redifd(bin);
		if (execve_str)
			free(execve_str);
		if (status == 2)
			g_sig.exit_status = 130;
		else if (status == 3)
			g_sig.exit_status = 131;
		else if (status != 0)
			g_sig.exit_status = status >> 8;
		else if (status == 5)
			g_sig.exit_status = 1;
	}
}
