/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:29:51 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/15 09:29:53 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void sinkIsland(int **map, int row, int col) {
	if (row < 0 || col < 0 || map[0][col] == -1 || map[row] == NULL)
		return;
	if (map[row][col] == 1) {
		map[row][col] = 0;
		sinkIsland(map, row + 1, col);
		sinkIsland(map, row - 1, col);
		sinkIsland(map, row, col + 1);
		sinkIsland(map, row, col - 1);
	}
}