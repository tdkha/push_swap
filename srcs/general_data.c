/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:50:35 by ktieu             #+#    #+#             */
/*   Updated: 2024/07/16 13:05:19 by ktieu            ###   ########.fr       */
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

static void	flat(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->av[i])
	{
		if (!is_complex_arg(data->av[i]))
		{
			data->flat_av[j] = ft_strdup(data->av[i]);
			if (!data->flat_av[j])
				return (ft_multiple_free_set_null(&data->flat_av));
			j++;
		}
		else
		{
			if (complex_arg_handler(data, &i, &j) == 0)
				return (ft_multiple_free_set_null(&data->flat_av));
		}
		i++;
	}
	data->ac = j;
	data->flat_av[j] = NULL;
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

	flat_av_size = 0;
	data->ac = ac;
	data->av = av;
	if (ac - 1 <= 20)
		data->max_chunks = 1;
	else if (ac - 1 <= 100)
		data->max_chunks = 4;
	else
		data->max_chunks = 10;
	flat_av_size = ft_flat_av_size(av);
	data->flat_av = (char **)malloc(sizeof(char *) * (flat_av_size + 1));
	if (!data->flat_av)
		ft_exit("Error\n", 1);
	ft_bzero(data->flat_av, sizeof(flat_av_size + 1));
	flat(data);
	data->total_amt = data->ac - 1;
}
