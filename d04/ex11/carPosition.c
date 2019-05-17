/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 13:10:00 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/13 13:10:01 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int carPosition(unsigned int parkingRow) {
    int ct = -1;
    while (parkingRow > 0) {
        ct++;
        parkingRow = parkingRow / 2;
    }
    return ct;
}
