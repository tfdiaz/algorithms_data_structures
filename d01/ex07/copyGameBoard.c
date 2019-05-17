/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:15:07 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/08 16:15:09 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct s_node *cloneGameBoard(struct s_node *node) {
    struct s_node *head = node;
    struct s_node *ret;
    struct s_node *cpy;
    struct s_node *tmp;
    while (node != NULL) {
        tmp = node->next;
        cpy = (struct s_node *)malloc(sizeof(struct s_node));
        cpy->value = node->value;
        cpy->random = node->random;
        node->next = cpy;
        node->next->next = tmp;
        node = tmp;
    }
    node = head;
    while (node != NULL) {
        if (node->next != NULL) {
            if (node->next->random != NULL)
                node->next->random = node->random->next;
            else
                node->next->random = node->random;
        }
        if (node != NULL)
            node = node->next->next;
        else
            node = node->next;
    }
    node = head;
    ret = node->next;
    cpy = ret;
    while (node != NULL && cpy != NULL) {
        if (node->next != NULL)
            node->next = node->next->next;
        else
            node->next = node->next;
        if (cpy->next != NULL)
            cpy->next = node->next->next;
        else
            cpy->next = node->next;
        node = node->next;
        cpy = cpy->next;
    }
    node = head;
    return ret;
}

