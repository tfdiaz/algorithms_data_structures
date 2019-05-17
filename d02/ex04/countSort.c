/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:45:06 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/09 18:45:07 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

void countSort(unsigned char *utensils, int n) {
    unsigned char *output = (unsigned char*)malloc(sizeof(unsigned char) * n);
    unsigned char *count = (unsigned char*)malloc(sizeof(unsigned char) * 15);

    for (int i = 0; i < 15; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[utensils[i]]++;

    int j = 0;
    for (int i = 0; i <= 15; i++) {
        int tmp = count[i];
        while (tmp--) {
            output[j] = i;
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        utensils[i] = output[i];
    }
    free(output);
    free(count);
}
