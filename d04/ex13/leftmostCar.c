/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:29:16 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/13 13:29:18 by tdiaz            ###   ########.fr       */
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

int leftmostCar(unsigned int parkingRow) {
    int ct = -1;
    while (parkingRow > 0) {
        ct = addone(ct);
        parkingRow = parkingRow >> 1;
    }
    return ct;
}
