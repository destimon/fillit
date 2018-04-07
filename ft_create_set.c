/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:12:06 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/07 17:42:00 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure 	*ft_create_set(t_figure *fig)
{
	t_figure	*prev;
	t_figure	*start;

	start = fig;
	prev = fig;
	fig = fig->next;
	while (i < huy)
	{
		while (fig)
		{
			//fig->scheme->x += prev->scheme->x;
		//	fig->scheme->y += prev->scheme->y;
			fig->scheme = fig->scheme->next;
			printf("%d\n", fig->scheme->x);
			prev = fig;
			fig = fig->next;
		}
		i++;
	}
	return (start);
}
