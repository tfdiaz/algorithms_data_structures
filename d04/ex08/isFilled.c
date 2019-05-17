/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:29:44 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/13 10:29:51 by tdiaz            ###   ########.fr       */
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

int isFilled(unsigned int parkingRow) {
    if (((addone(parkingRow)) & (parkingRow)) == 0 && parkingRow > 0)
        return 1;
    return 0;
}
