/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:47:00 by etermeau          #+#    #+#             */
/*   Updated: 2014/12/22 18:13:15 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <fcntl.h>
#include <libft.h>
#include "fdf.h"

char	**read_fdf(char **av)
{
	char	**tab;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
		i++;
	close(fd);
	fd = open(av[1], O_RDONLY);
	tab = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (get_next_line(fd, &line))
	{
		tab[i] = ft_strdup(line);
		i++;
		free(line);
	}
	close(fd);
	tab[i] = NULL;
	return (tab);
}

int		expose_hook(t_env *e)
{
	ft_draw(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		e.map = ft_format_tab(read_fdf(av));
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WID, HEIG, "FDF");
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_putstr("Error");
	return (0);
}