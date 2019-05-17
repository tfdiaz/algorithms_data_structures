/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:37:13 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/15 10:37:15 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "stdlib.h"
#include <stdio.h>
#include <limits.h> 

int load(int *arr, int eat, int dex) {
	if (arr[dex] - eat >= 0) {
		arr[dex] -= eat;
		return 1;
	}
	return 0;
}

int uts(struct s_people **people, int nbTable, int *tct) {
	int b = 0;
	int *tmp;

	if (*people == NULL)
		return 1;
	for (int i = 0; i < nbTable; i++) {
		tmp = tct;
		b = load(tmp, people[0]->time, i);
		if (b)
			return uts((people) + 1, nbTable, tmp);
	}
	return b;
}

int isPossible(struct s_people **people, int nbTable, int totalTime) {
	int *tct = (int*)malloc(sizeof(int) * nbTable);

	for (int i = 0; i < nbTable; i++)
		tct[i] = totalTime;
	return uts(people, nbTable, tct);
 }
