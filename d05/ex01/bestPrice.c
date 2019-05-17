/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 07:48:46 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/15 07:48:48 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void funct(int sum, double cur, double *prices, double *ret) {
	double tmp;

	if (sum == 0) {
		if (cur > ret[0])
			ret[0] = cur;
	}
	else {
		for (int i = 0; i < sum; i++) {
			tmp = cur;
			tmp += prices[sum - i];
			funct(i, tmp, prices, ret);
		}
	}
}

double bestPrice(int pizzaSize, double *prices) {
	double ret[1];

	funct(pizzaSize, (double)0, prices, ret);
	return ret[0];
}