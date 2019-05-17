/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:19:01 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/05 15:19:03 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"

int searchPrice(struct s_art **arts, int n, char *name) {
    int r = n - 1;
    int l = 0;
    int i;
    int m;

    while (l <= r) {
        i = (l + r) / 2;
        if ((m = strcmp(arts[i]->name, name)) == 0)
            return arts[i]->price;
        if (m < 0)
            l = i + 1;
        else
            r = i - 1;
    }
    return -1;
}
