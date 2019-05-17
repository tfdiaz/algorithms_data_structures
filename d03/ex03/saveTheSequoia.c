/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 23:00:42 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/10 23:00:44 by tdiaz            ###   ########.fr       */
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

void	saveTheSequoia(struct s_node **root) {
    if (*root == NULL)
        return;
    heapify(root, (struct s_node**)NULL);
    printf("\n");
}