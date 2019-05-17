/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:58:28 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/13 09:58:29 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int setPlace(unsigned int parkingRow, int pos) {
    unsigned int val;
    val = 1 << pos;
    return parkingRow | val;
}