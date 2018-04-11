/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:12:06 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/10 14:11:17 by dcherend         ###   ########.fr       */
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
	while (fig)
	{	
		prev = fig;
		fig = fig->next;
	}
	return (start);
}
