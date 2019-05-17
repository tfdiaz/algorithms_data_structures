/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:35:48 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/07 19:35:50 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct s_node *init(void) {
    struct s_node *head = (struct s_node *)malloc(sizeof(struct s_node));
    head->c = CS[0];
    head->next = head;
    head->prev = head;
    struct s_node *pres = head;
    for (int i = 1; CS[i] != '\0'; i++) {
        struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
        new->c = CS[i];
        new->next = head;
        new->prev = pres;
        pres->next = new;
        pres = new;
    }
    head->prev = pres;
    return head;
}

void shift(struct s_node **base, int move) {
    if (move >= 0) {
        while (move != 0) {
            *base = (*base)->next;
            move--;
        }
    }
    else {
        while (move != 0) {
            *base = (*base)->prev;
            move++;
        }
    }
}

char *precious(int *text, int size) {
    struct s_node *base;
    base = init();
    int move;
    int i;
    char *ret = (char *)malloc(sizeof(char) * size + 1);
    for (i = 0; i < size; i++) {
        move = text[i];
        shift(&base, move);
        ret[i] = base->c;
    }
    ret[i] = '\0';
    return ret;
}
