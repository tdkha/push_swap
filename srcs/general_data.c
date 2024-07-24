/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:50:35 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/24 17:55:56 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_complex_arg(char *str)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
			word_count++;
		while (str[i] && !ft_isspace(str[i]))
			i++;
	}
	return (word_count > 1);
}

static int	complex_arg_handler(t_data *data, int *i, int *j)
{
	int		k;
	char	**flat;

	k = 0;
	flat = ft_split(data->av[*i], ' ');
	if (!flat)
		return (0);
	while (flat[k])
	{
		data->flat_av[*j] = ft_strdup(flat[k]);
		if (!data->flat_av[*j])
		{
			ft_multiple_free_set_null(&flat);
			return (0);
		}
		(*j)++;
		k++;
	}
	ft_multiple_free_set_null(&flat);
	return (1);
}

static int	flat(t_data *data, int i, int j)
{
	while (data->av[i])
	{
		ft_split_skip_delimiter((const char **)&data->av[i], ' ');
		if (*data->av[i])
		{
			if (!is_complex_arg(data->av[i]))
			{
				data->flat_av[j] = ft_strdup(data->av[i]);
				if (!data->flat_av[j])
					return (0);
				j++;
			}
			else
			{
				if (complex_arg_handler(data, &i, &j) == 0)
					return (0);
			}
		}
		else
			return (0);
		i++;
	}
	data->ac = j;
	return (1);
}

static size_t	ft_flat_av_size(char **av)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (av[i])
	{
		size += ft_wordcount_delimiter(av[i], ' ');
		i++;
	}
	return (size);
}

void	ps_general_data_init(
	t_data *data,
	int ac,
	char **av
)
{
	size_t	flat_av_size;

	ft_bzero(data, sizeof(t_data));
	flat_av_size = 0;
	data->flat_error = 0;
	data->ac = ac;
	data->av = av;
	if (ac - 1 <= 20)
		data->max_chunks = 1;
	else if (ac - 1 <= 100)
		data->max_chunks = 4;
	else
		data->max_chunks = 10;
	flat_av_size = ft_flat_av_size(av);
	data->flat_av = (char **)ft_calloc((flat_av_size + 1), sizeof(char *));
	if (!data->flat_av)
		ft_exit("Error", 1);
	if (flat(data, 0, 0) == 0)
	{
		ft_multiple_free_set_null(&data->flat_av);
		ft_exit("Error", 1);
	}
	data->total_amt = data->ac - 1;
}
