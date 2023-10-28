/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:34:04 by alletond          #+#    #+#             */
/*   Updated: 2023/10/28 23:25:14 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_nbr(t_stack *list, int value)
{
	t_stack	*nouvelt_stack;

	nouvelt_stack = (t_stack *)malloc(sizeof(t_stack));
	{
		nouvelt_stack->valeur = value;
		nouvelt_stack->next = list;
		if (list)
		{
			list->prev = nouvelt_stack;
		}
		nouvelt_stack->prev = NULL;
		list = nouvelt_stack;
	}
	return (list);
}

t_stack	*remlistelir_liste(int argc, char **argv, int *len)
{
	t_stack	*liste;
	int		valeur;

	liste = NULL;
	*len = 0;
	for (int i = 1; i < argc; i++)
	{
		valeur = atoi(argv[i]);
		liste = add_nbr(liste, valeur);
		(*len)++;
	}
	return (liste);
}

void	draw_list(t_stack *list)
{
	while (list)
	{
		printf("%d ", list->valeur);
		list = list->next;
	}
	printf("\n");
}
int	ft_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void solver2(t_game *nbr, t_stack *a, t_stack *b)
{	
		if (nbr->move_type == RA_RB)
			solve_rr(nbr, a, b);
		// if (nbr->move_type == RRA_RB)
		// 	solve_rra_rb(nbr, a, b);
		if (nbr->move_type == RA_RRB)
			solve_ra_rrb(nbr, a, b);
		if (nbr->move_type == RRA_RRB)
			solve_rrr(nbr, a, b);
		pb(&a, &b, 1);
}
void solver(t_stack *a, t_stack *b)
{
	t_game *res;

	int i = 0;
	pb(&a, &b, 1);
	pb(&a, &b, 1);
	while (i < 5)
	{
		draw_list(a);
		draw_list(b);
		res = find_best_nb(a, b);
		//display_game(res);
		solver2(res, a, b);
		i++;
	}
}
int	main(int argc, char **argv)
{
	t_stack	*liste;
	t_stack	*liste_b;
	int		len;
	t_stack	*temliste;

	liste = NULL;
	liste_b = NULL;
	len = 0;
	liste = remlistelir_liste(argc, argv, &len);
	solver(liste, liste_b);
	draw_list(liste);
	draw_list(liste);
	while (liste != NULL)
	{
		temliste = liste;
		liste = liste->next;
		free(temliste);
	}
	return (0);
}
