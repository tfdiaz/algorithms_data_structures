/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 09:16:35 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/16 09:16:37 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		minPersons(int elements, int minPercentage) {
    int ct = 1;
    double p = 1.0;
    double t = 0.0;
    if (elements == 0 || minPercentage == 0)
        return 0;
    double min = (double)minPercentage / 100.0;
    int sub = 1;
    while (t < min) {
        p *= (double)(elements - sub) / (double)elements;
        t = 1 - p;
        sub++;
        ct++;
    }
    return ct;
}
