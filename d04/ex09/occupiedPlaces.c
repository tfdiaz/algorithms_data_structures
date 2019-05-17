/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:58:50 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/13 10:58:53 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int addone(int x) {
    int m = 1;
    while (x & m) {
        x ^= m;
        m <<= 1;
    }
    x ^= m;
    return x;
}

int occupiedPlaces(unsigned int parkingRow) {
    int ct = 0;
    while (parkingRow) {
        parkingRow = (parkingRow) & ~(~parkingRow + 1);
        ct = addone(ct);
    }
    return ct;
}
