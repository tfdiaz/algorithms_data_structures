/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:44:15 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/13 13:44:16 by tdiaz            ###   ########.fr       */
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

int longestSequence(unsigned int parkingRow) {
    int ct = 0;
    if (parkingRow > 0)
        ct = addone(ct);
    unsigned shift = parkingRow << 1;
    parkingRow &= shift;
    while (parkingRow > 0) {
        ct = addone(ct);
        shift = parkingRow << 1;
        parkingRow &= shift;
    }
    return ct;
}