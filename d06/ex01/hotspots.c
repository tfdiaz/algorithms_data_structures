/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 08:05:50 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/16 08:05:53 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int selectHotspots(struct s_hotspot **hotspots) {
    int ct = 1;
    if (*hotspots == NULL || hotspots[1] == NULL)
        return 0;
    for (int i = 1, j = 0; hotspots[i] != NULL; i++) {
        if (hotspots[j]->radius + hotspots[j]->pos <=
            hotspots[i]->pos - hotspots[i]->radius) {
            j = i;
            ct++;
        }
    }
    return ct;
}
