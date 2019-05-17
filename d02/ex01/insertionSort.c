/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:21:37 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/09 13:21:39 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void insertionSort(struct s_player **players) {
    int i = 1;
    int j;
    struct s_player *tmp;
    while (players[i] != NULL) {
        tmp = players[i];
        j = i - 1;
        while (j >= 0 && players[j]->score < tmp->score) {
            players[j + 1] = players[j];
            j = j - 1;
        }
        players[j+1] = tmp;
        i++;
    }
}
