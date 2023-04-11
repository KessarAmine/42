/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:31:54 by kmohamed          #+#    #+#             */
/*   Updated: 2023/01/27 16:33:31 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minTalkLib.h"
#include "headers/ft_printfLib.h"

void	send_bit(int pid, char *str, size_t len)
{
	int		bit_order;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		bit_order = 0;
		while (bit_order < 7)
		{
			if ((str[i] >> bit_order) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit_order++;
			usleep(250);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		if (has_nonenumeric(argv[1]) == 0)
		{
			ft_printf("Input Error! Incorrect PID format\n");
			return (0);
		}
		pid = ft_atoi(argv[1]);
		if (kill(pid, 0) == -1)
		{
			ft_printf("Input Error! PID not found\n");
			return (0);
		}
		str = argv[2];
		send_bit(pid, str, ft_strlen(str));
	}
	else
		ft_printf("Input Error! Please Check the requirements...\n");
}
