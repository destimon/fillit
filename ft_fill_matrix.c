/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <dcherend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:21:20 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/14 18:29:10 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// static	void		ft_try_put(t_el *el, t_field *fl, int i, int j,
// 						char letter)
// {
// 	/* Check for free space */
// 	if (fl->field[i][j] == '.' && el->x == i && el->y == j)
// 		fl->field[i][j] = letter;
// 	else
// 	{
// 		if (i + 1 > fl->size) /* X pos bypassed */
// 		{
// 			if (j + 1 > fl->size) /* Y pos bypassed */
// 			{
// 				fl->field = ft_expand_matrix(fl); /* So we'll expand */
// 				ft_try_put(el, fl, i, j, letter);	/* And try again */
// 			}
// 			else /* Y move */
// 			{
// 				ft_try_put(el, fl, i, j + 1, letter);
// 			}
// 		}
// 		else /* X move */
// 			ft_try_put(el, fl, i + 1, j, letter);
// 	} 
// }

// static	void	**ft_enter_figure(t_figure *fig, t_field *fl)
// {
// 	t_el	*el;
// 	int 	i;
// 	int 	j;

// 	el = fig->scheme;
// 	/* Walk on the element list */
// 	while (el)
// 	{
// 		i = 0;
// 		j = 0;
// 		/* Walk on the matrix */
// 		while (i < fl->size)
// 		{
// 			while (j < fl->size)
// 			{
// 				ft_try_put(el, fl, i, j, fig->letter);
// 				j++;
// 			}
// 			i++;
// 		}
// 		el = el->next;
// 	}
// }

void			ft_fill_matrix(t_figure *fig)
{
	t_field	*fl;
	char	letter;
	int		i;

	i = 0;
	letter = 'A';
	/* Init 2x2 matrix */
	//fl = ft_alloc_field(5);
	//ft_print_field(fl);
	//fl = ft_realloc_field(fl, 10);
	//ft_place_field(fl, fig, 1, 1);
	//ft_print_field(fl);
	/* Iterate figures to matrix */
	// while (fig)
	// {
	// 	fig->letter = letter;
	// 	ft_enter_figure(fig, matrix);
	// 	letter++;
	// 	fig = fig->next;
	// }
	// return (matrix);
}
