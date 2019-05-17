/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printYoungest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:13:30 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/10 10:13:31 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int *merges(int *arr, int lo, int hi) {
    int m;
    int *v1;
    int *v2;
    int *ret = (int*)calloc(2, sizeof(int));
    if (arr[lo] < arr[hi]) {
        ret[0] = arr[lo];
        ret[1] = lo;
    }
    else {
        ret[0] = arr[hi];
        ret[1] = hi;
    } 
    if (lo < hi) {
        m = (lo + hi) / 2;
        v1 = merges(arr, lo, m);
        v2 = merges(arr, m + 1, hi);
        if (v1[0] < v2[0]) {
            ret = v1;
            free(v2);
        }
        else {
            ret = v2;
            free(v1);
        }
    }
    return ret;
}

void printYoungest(int *ages, int length) {
    int *ret;
    ret = merges(ages, 0, length - 1);
    printf("Youngest : %i\t Index: %i\n", ret[0], ret[1]);
    free(ret);
}