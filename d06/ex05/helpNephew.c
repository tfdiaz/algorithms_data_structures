/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpNephew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:17:01 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/16 12:17:03 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

double probs(int nStairs, int nPunch, int nephewStair, double **cache) {
    double p = 0.0;
    if (nStairs <= nephewStair)
        return 0.0;
    if (nPunch == 0)
        return 1.0;
    if (cache[nPunch][nStairs] > -0.5)
        return cache[nPunch][nStairs];
    for (int i = nephewStair + 1; i < nStairs; i++)
        p += probs(i, nPunch - 1, nephewStair, cache) * (double)(1.0 / (double)nStairs);
    cache[nPunch][nStairs] = p;
    return p;
}

double	probaNephewWillLive(int nStairs, int nPunch, int nephewStair) {
    double **cache = (double **)malloc(sizeof(double*) * (nPunch + 1));
    for (int i = 0; i <= nPunch; i++) {
        cache[i] = (double *)malloc(sizeof(double) * (nStairs + 1));
        for (int j = 0; j <= nStairs; j++)
            cache[i][j] = -1.0;
    }
    return probs(nStairs, nPunch, nephewStair, cache);
}
