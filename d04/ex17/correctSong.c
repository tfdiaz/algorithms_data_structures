/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctSong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:22:31 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/14 09:22:33 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void	correctSong(struct s_bit *bit, int l, int row, int col, int dist) {
    if (bit == NULL)
        return;
    unsigned int val = 1 << col;
    for (int i = row, j = 0; i < l && j < dist; i++, j++)
        bit->arr[i] |= (int)val;
}
