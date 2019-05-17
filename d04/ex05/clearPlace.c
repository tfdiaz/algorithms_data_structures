/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearPlace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:44:17 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/13 09:44:20 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int clearPlace(unsigned int parkingRow, int pos) {
    unsigned int val;
    val = 1 << pos;
    return (parkingRow & (~val));
}
