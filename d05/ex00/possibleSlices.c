/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:43:32 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/14 14:43:42 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void funct(int sum, struct s_array *arr) {
	struct s_array	*tmp;

	if (sum == 0)
		arrayPrint(arr);
	else {
		for (int i = 0; i < sum; i++) {
			tmp = arrayClone(arr);
			arrayAppend(tmp, sum - i);
			funct(i, tmp);
		}
	}
}

void printPossibleSlices(int pizzaSize) {
	struct s_array *arr = arrayInit();

	funct(pizzaSize, arr);
}
