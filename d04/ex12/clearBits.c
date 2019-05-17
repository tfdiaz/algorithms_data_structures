/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearBits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:22:20 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/13 13:22:23 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int minone(int x) {
    int m = 1;
    while (!(x & m)) {
        x ^= m;
        m <<= 1;
    }
    x ^= m;
    return x;
}

unsigned int clearBits(unsigned int parkingRow, int n) {
    unsigned int val = 1 << (n);
    val = minone(val);
    return parkingRow & (~val);
}
