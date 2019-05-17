/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piano.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:14:54 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/13 18:14:55 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int	**pianoDecompress(struct s_bit *bit, int l) {
    int **ret = (int **)malloc(sizeof(int *) * (bit->n + 1));
    for (int i = 0; i < bit->n; i++) {
        ret[i] = (int *)malloc(sizeof(int) * l);
        for (int j = 0; j < bit->n; j++) {
            ret[i][j] = 0;
        }
    }
    ret[bit->n] = NULL;
    for (int i = 0; i < bit->n; i++) {
        unsigned int val = bit->arr[i];
        for (int j = 0; val > 0; j++) {
            if (val & 1)
                ret[i][j] = 1;
            val = val >> 1;
        }
    }
    return ret;
}
