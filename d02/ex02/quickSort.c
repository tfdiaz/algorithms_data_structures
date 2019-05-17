/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:43:55 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/09 13:43:56 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void swap(struct s_player **a, struct s_player **b) {
    struct s_player *tmp = *a;
    *a = *b;
    *b = tmp;
}

int part(struct s_player **players, int lo, int hi) {
    int i;
    int p;
    int firsthigh;

    p = hi; 
    firsthigh = lo;
    for (i = lo; i < hi; i++) {
        if (players[i]->score > players[p]->score) {
            swap(&players[i], &players[firsthigh]);
            firsthigh++;
        }
    }
    swap(&players[p], &players[firsthigh]);
    return (firsthigh);
}

void quick(struct s_player **players, int lo, int hi) {
    int p;
    if (lo < hi) {
        p = part(players, lo, hi);
        quick(players, lo, p - 1);
        quick(players, p + 1, hi);
    }
}

void quickSort(struct s_player **players) {
    int len;
    for (len = 0; players[len] != NULL; len++)
        ;
    quick(players, 0, len - 1);
}
