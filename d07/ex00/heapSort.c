/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 08:09:27 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/17 08:09:29 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

void swap(struct s_art *a, struct s_art *b) {
    char *tmp = a->name;
    int tmp2 = a->price;
    a->name = b->name;
    a->price = b->price;
    b->name = tmp;
    b->price = tmp2;
}

void heapify(struct s_art **arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && strcmp(arr[l]->name, arr[largest]->name) >= 0)
        largest = l;
    if (r < n && strcmp(arr[r]->name, arr[largest]->name) >= 0)
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(struct s_art **masterpiece, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(masterpiece, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(masterpiece[0], masterpiece[i]);
        heapify(masterpiece, i, 0);
    }
}
