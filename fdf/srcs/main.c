/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 18:16:04 by etermeau          #+#    #+#             */
/*   Updated: 2016/05/02 10:19:32 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../includes/fdf.h"

int			ft_check_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_code_erreur(1);
	return (fd);
}

void		ft_read_file(char *file, t_point ****tab)
{
	char	*matrix;
	int		line;
	int		fd;

	fd = ft_check_file(file);
	line = 0;
	while (get_next_line(fd, &matrix))
		line++;
	close(fd);
	ft_check_file(file);
	if (!(*tab = (t_point ***)malloc(sizeof(t_point **) * line) + 1))
		ft_code_erreur(2);
	line = 0;
	while (get_next_line(fd, &matrix))
	{
		(*tab)[line] = ft_attribut(matrix, line, 0);
		ft_no_space(matrix, 0);
		line++;
		free(matrix);
	}
	(*tab)[line] = NULL;
}

int			main(int ac, char *av[])
{
	t_point	***data;

	data = NULL;
	if (ac == 2)
	{
		ft_read_file(av[1], &data);
		if (data == NULL)
			return (0);
		ft_check_map(&data);
	}
	else
		ft_code_erreur(0);
	return (0);
}
