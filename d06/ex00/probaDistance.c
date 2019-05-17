/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 07:46:38 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/16 07:46:39 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probaDistance(int dist, int *locations, int n) {
    double prob = 0;
    double ct = 1;
    for (int j = 0; j < n; j++) {
        for (int i = j + 1; i < n; i++) {
            if (locations[i] - locations[j] > dist)
                prob += 1;
            ct += 1;
        }
    }
    return (ct - 1 > 0) ? prob / (ct - 1) : 0;
}
