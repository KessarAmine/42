/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:31:46 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/04 13:03:11 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minTalkLib.h"
#include "headers/ft_printfLib.h"

t_message	g_msg;

void	bit_handler(int bit)
{
	g_msg.c += ((bit & 1) << g_msg.bit_order);
	g_msg.bit_order++;
	if (g_msg.bit_order == 7)
	{
		if (!g_msg.c)
			ft_printf("\n");
		else
			ft_printf("%c", g_msg.c);
		g_msg.c = 0;
		g_msg.bit_order = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bit_handler);
		signal(SIGUSR1, bit_handler);
		pause();
	}
	return (0);
}
