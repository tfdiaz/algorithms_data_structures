/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:31:00 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/13 09:31:03 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int getPlace(unsigned int parkingRow, int pos) {
    unsigned int val;
    val = 1 << pos;
    return parkingRow & val;
}
