/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:26:44 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/10 19:26:46 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "header.h"

int *all(struct s_node *root, int * a, int height, int min, int max) {

    int tmpheight;
    if (root == NULL)
        return a;
    if (root->value < a[0])
        a[0] = root->value;
    if (root->value > a[1])
        a[1] = root->value;

    a[2]++;
    if (root->value < min || root->value > max)
        a[4] = 0;
    
    a = all(root->left, a, height + 1, min, root->value -1);
    tmpheight = a[3];
    a = all(root->right, a, height + 1, root->value + 1, max);
    
    if (abs(tmpheight - a[3]) > 2)
        a[5] = 0;
    if (height > a[3])
        a[3] = height;
    return a;
}

struct s_info   getInfo(struct s_node *root) {
    int *a =(int*)malloc(sizeof(int) * 6);
    struct s_info data;
    a[0] = INT_MAX;
    a[1] = INT_MIN;
    a[2] = 0;
    a[3] = 0;
    a[4] = 1;
    a[5] = 1;
    a = all(root, a, 0, INT_MIN, INT_MAX);
    data.min = a[0];
    data.max = a[1];
    data.elements = a[2];
    data.height = a[3];
    data.isBST = a[4];
    data.isBalanced = a[5];
    return data;
}