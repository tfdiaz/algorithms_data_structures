/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:49:01 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/17 10:49:03 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

struct s_node *utls(int *arr, int l, int r) {
    struct s_node *new = NULL;
    int m = (l + r) / 2;
    if (l < r) {
        new = (struct s_node *)malloc(sizeof(struct s_node));
        new->left = NULL;
        new->right = NULL;
        new->value = arr[m];
        new->left = utls(arr, l, m);
        new->right = utls(arr, m + 1, r);
    }
    return new;
}

struct s_node *createBST(int *arr, int n) {
    struct s_node *ret;

    ret = utls(arr, 0, n);
    return ret;
}
