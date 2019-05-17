/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 08:02:34 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/15 08:02:35 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

double funct(int sum, double *prices, double *cache) {
	double	max;

	max = prices[sum];
	if (cache[sum] > 1) {
		return cache[sum];
	}
	for (int i = 1; i <= sum / 2; i++) {
		if (funct(i, prices, cache) + funct(sum - i, prices, cache) > max)
			max = cache[i] + cache[sum - i];
	}
	cache[sum] = max;
	return cache[sum];
}

double optimizedBestPrice(int pizzaSize, double *prices) {
	double cache[101];

	for (int i = 0; i < 101; i++)
		cache[i] = 0.0;
	cache[0] = prices[0];
	cache[1] = prices[1];
	return funct(pizzaSize, prices, cache); 
}
