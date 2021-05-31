/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:29:53 by tsaiyan           #+#    #+#             */
/*   Updated: 2021/05/21 20:29:55 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_puts_and_change_global(char *str, int error)
{
	if (str)
	{
		ft_putstr(str);
		write(1, "\n", 1);
		g_sig.exit_status = error;
	}
	return (0);
}

int	cd_check_dir(t_bin *bin)
{
	DIR	*check_dir;

	check_dir = opendir(bin->argv[1]);
	if (check_dir == NULL)
	{
		if (errno == EBADF || errno == 20)
			printf("bash: cd: %s: Not a directory\n", bin->argv[1]);
		if (errno == ENOENT)
			printf("bash: cd: %s: No such file or directory\n", bin->argv[1]);
		errno = 0;
		g_sig.exit_status = 1;
		return (-1);
	}
	if (check_dir)
		closedir(check_dir);
	return (0);
}

int	cd_part_2(t_bin *bin, char **argv)
{
	if (cd_with_minus(bin, argv) == 2)
	{
		if (chdir(ft_get_value(bin->export, "HOME")) == -1)
			return (ft_puts_and_change_global("bash: cd: HOME not set", 1));
		else
			return (change_oldpwd(bin, bin->temp_old_dir));
	}
	if (cd_with_minus(bin, argv) == -1)
		return (cd_outputs(argv, 1));
	if (cd_check_dir(bin) == -1)
		return (-1);
	if (g_sig.exit_status != 1 && argv[1] && chdir(argv[1]) == -1)
		cd_outputs(argv, 2);
	else
		change_oldpwd(bin, bin->temp_old_dir);
	g_sig.exit_status = 0;
	return (0);
}

int	ft_cd(t_bin *bin, char **argv)
{
	bin->temp_old_dir = getcwd(bin->dir, PATH_MAX);
	if (!argv[1])
	{
		bin->home_path = ft_get_value(bin->export, "HOME");
		if (bin->home_path)
		{
			chdir(bin->home_path);
			change_oldpwd(bin, bin->temp_old_dir);
		}
		else
			return (ft_puts_and_change_global("bash: cd: HOME not set", 1));
	}
	if (cd_with_minus(bin, argv) == 1)
	{
		if (chdir(ft_get_value(bin->export, "OLDPWD")) == -1)
			return (ft_puts_and_change_global("bash: cd: OLDPWD not set", 1));
		else
			return (change_oldpwd(bin, bin->temp_old_dir));
	}
	return (cd_part_2(bin, argv));
}
