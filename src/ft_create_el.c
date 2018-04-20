/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_el.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:01:09 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/19 18:02:01 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_el	*ft_create_el(int x, int y)
{
	t_el	*new;

	new = (t_el*)malloc(sizeof(t_el));
	if (new)
	{
		new->x = x;
		new->y = y;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
