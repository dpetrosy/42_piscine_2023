/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:35:39 by dapetros          #+#    #+#             */
/*   Updated: 2023/10/29 22:08:28 by dapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "get_next_line.h"

char	**get_default_nums(void)
{
	char	**default_mat;

	default_mat = (char **)malloc(sizeof(char *) * DICT_SIZE);
	if (!default_mat)
		return (NULL);
	set_values(default_mat);
	return (default_mat);
}

bool	is_valid_num(char *num)
{
	char	**nums;
	int		i;

	nums = get_default_nums();
	i = -1;
	while (++i < DICT_SIZE)
	{
		if (ft_strcmp(nums[i], num) == 0)
		{
			free_str_matrix(nums, DICT_SIZE);
			return (true);
		}
	}
	free_str_matrix(nums, DICT_SIZE);
	return (false);
}

bool	process_line(t_line *dict, char *line, int *line_count)
{
	int		i;
	char	*local_line;
	char	num[39];

	i = -1;
	while (line[++i])
		if (line[i] >= 33 && line[i] <= 126)
			break ;
	if (line[i] == '\0')
		return (true);
	if (!check_num(line, num))
		return (false);
	if (!is_valid_num(num))
		return (true);
	local_line = line;
	while (*local_line != ':')
		++local_line;
	if (*local_line == '\0')
		return (false);
	dict[*line_count].value = get_value(++local_line);
	if (!dict[*line_count].value)
		return (false);
	dict[*line_count].key = ft_strdup(num);
	*line_count += 1;
	return (true);
}

bool	process_dict(t_line *dict, int fd)
{
	int		lines_count;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (false);
	lines_count = 0;
	while (line)
	{
		if (!process_line(dict, line, &lines_count))
		{
			free(line);
			return (false);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (true);
}

t_line	*parse_dict(char *filename)
{
	t_line	*dict;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	dict = (t_line *)malloc(sizeof(t_line) * DICT_SIZE);
	if (!dict)
	{
		close(fd);
		return (NULL);
	}
	fill_dict_null(dict);
	if (!process_dict(dict, fd))
	{
		close(fd);
		free_dict(dict);
		return (NULL);
	}
	close(fd);
	return (dict);
}
