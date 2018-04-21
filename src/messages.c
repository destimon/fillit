/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:18:08 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/21 18:40:21 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	throw_error(char *message)
{
	write(1, "error\n", 6);
	if (message && 0)
	{
		ft_putstr_fd(message, 1);
		ft_putchar_fd('\n', 1);
	}
	exit(1);
}
