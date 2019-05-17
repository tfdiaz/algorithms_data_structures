/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:10:37 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/14 10:16:34 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void aloneCans(int *arr, int n) {
    int val = 0;
    for (int i = 0; i < n; i++)
        val ^=arr[i];
    int ind = 0;
    int f = arr[0] & val;
    for (ind = 0; ind < n; ind++) {
        if ((arr[ind] & val) != f)
            break;
    }

    val = 0;
    for (int i = 0; i < ind; i++)
        val ^=arr[i];
    for (int i = 0; i < ind; i++) {
        if ((arr[i] ^ val) == 0)
            printf("%d\n", arr[i]);
    }

    val = 0;
    for (int i = ind; i < n; i++)
        val ^=arr[i];
    for (int i = ind; i < n; i++) {
        if ((arr[i] ^ val) == 0)
            printf("%d\n", arr[i]);
    }
}
