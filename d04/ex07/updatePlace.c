/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:10:31 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/13 10:10:32 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value) {
    return (value) ? (parkingRow | (1 << pos)) : (parkingRow & (~(1 << pos)));
}
