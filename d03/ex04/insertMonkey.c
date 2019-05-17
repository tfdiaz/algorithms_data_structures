/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertMonkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:54:22 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/11 13:54:24 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

void	heapify(struct s_node **root, struct s_node **pred) {
    struct s_node *max;
    struct s_node *tmp;
    int flag = 0;
    if (*root == NULL)
        return;
    pred = root;
    heapify(&(*root)->left, pred);
    heapify(&(*root)->right, pred);
    max = *root;
    flag = 0;
    if ((*root)->left && (*root)->left->value > max->value) {
        flag = 0;
        max = (*root)->left;
    }
    if ((*root)->right && (*root)->right->value > max->value) {
        flag = 1;
        max = (*root)->right;
    }

    if (max != *root) {
        if (flag) {
            tmp = (*root)->left;
            (*root)->left = max->left;
                max->left = tmp;

            (*root)->right = max->right;
            max->right = *root;
            if (*pred && &(*pred)->right == root)
                (*pred)->right = max;
            else if (*pred && &(*pred)->left == root)
                (*pred)->left = max;
            *root = max;
        }
        else {
            tmp = (*root)->right;
            (*root)->right = max->right;
            max->right = tmp;

            (*root)->left = max->left;
            max->left = *root;
            if (*pred && &(*pred)->right == root)
                (*pred)->right = max;
            else if (*pred && &(*pred)->left == root)
                (*pred)->left = max;
            *root = max;
        }
        heapify(root, pred);
    }
}

unsigned int elements(struct s_node *root) {
    if (root == NULL)
        return 0;
    return elements(root->right) + elements(root->left) + 1;
}

void insertMonkey(struct s_node **root, struct s_node *monkey) {
    struct s_node *tmp;

    tmp = *root;
    unsigned int elem = elements(*root) + 1;
    unsigned int set = elem & 1;
    elem = elem >> 1;
    while (elem > 1) {
        if (elem & 1)
            tmp = tmp->right;
        else
            tmp = tmp->left;
        elem = elem >> 1;
    }
    if (set)
        tmp->right = monkey;
    else
        tmp->left = monkey;
    heapify(root, (struct s_node**)NULL);
}
