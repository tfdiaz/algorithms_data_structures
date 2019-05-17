/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:36:37 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/09 19:36:39 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	searchShifted(int *rocks, int length, int value) {
    int r = length - 1;
    int l = 0;
    int i;

    while (l <= r) {
        i = (l + r) / 2;
        if (rocks[i] == value) {
            while (rocks[i] == value && i > 0)
                i--;
            i++;
            return i;
        }
        if (rocks[i] < value)
            l = i + 1;
        else
            r = i - 1;
    }
    return -1;  
}
