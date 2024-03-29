/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:53:04 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:53:11 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reverse_arr(int *arr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
		i++;
	}
}
