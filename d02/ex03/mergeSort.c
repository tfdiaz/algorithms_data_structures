/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:41:32 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/09 14:41:35 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"


void merg(struct s_player ***players, int lo, int m, int hi) {
    struct s_player **low = (struct s_player **)malloc(sizeof(struct s_player*) * (m - lo + 2));
    struct s_player **high = (struct s_player **)malloc(sizeof(struct s_player*) * (hi - m + 2));
    int j;
    int k;
    int i;

    for (i = lo, j = 0; i <= m; i++, j++)
        low[j] = (*players)[i];
    low[j] = NULL;

    for (i = m + 1, j = 0; i <= hi; i++, j++)
        high[j] = (*players)[i];
    high[j] = NULL;

    i = lo;
    j = 0;
    k = 0;
    while (low[j] != NULL && high[k] != NULL) {
        if (low[j]->score < high[k]->score) {
            (*players)[i] = high[k];
            k++;
        }
        else {
            (*players)[i] = low[j];
            j++;
        }
        i++;
    }

    while (low[j] != NULL) {
        (*players)[i] = low[j];
        i++;
        j++;
    }
    while (high[k] != NULL) {
        (*players)[i] = high[k];
        i++;
        k++;
    }

    free(low);
    free(high);
}

void merges(struct s_player ***players, int lo, int hi) {
    int m;

    if (lo < hi) {
        m = (lo + hi) / 2;
        merges(players, lo, m);
        merges(players, m + 1, hi);
        merg(players, lo, m, hi);
    }
}

struct s_player **mergeSort(struct s_player **players) {
    int len;
    for (len = 0; players[len] != NULL; len++)
        ;
    merges(&players, 0, len - 1);
    return players;
}
