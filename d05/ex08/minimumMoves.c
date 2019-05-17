/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimumMoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:54:21 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/15 17:54:24 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int	minimumMoves(struct s_node *begin) {
	struct s_queue	*open_set = queueInit();
	struct s_dict	*closed_set = dictInit(100);
	struct s_node	*tmp;
	struct s_node	*empty = (struct s_node *)malloc(sizeof(struct s_node));
	int 			level = 0;

	enqueue(open_set, (void*)begin);
	enqueue(open_set, empty);
	while (open_set->first != NULL) {
		tmp = (struct s_node*)dequeue(open_set);
		if (tmp->isFinal)
			return (level);
		if (dictSearch(closed_set, tmp) == 0) {
			if (tmp == empty) {
				level++;
				enqueue(open_set, empty);
				if (open_set->first->value == (void*)empty)
					break;
				continue;
			}
			dictInsert(closed_set, tmp, 1);
			if (tmp->random != NULL)
				enqueue(open_set, tmp->random);
			if (tmp->next != NULL)
				enqueue(open_set, tmp->next);
		}
	}
	return (-1);
}
