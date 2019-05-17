/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:07:10 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/09 10:07:11 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

struct s_elem {
    int val;
    struct s_stone *start;
    struct s_stone *end;
    struct s_elem *next;
};

void swap(struct s_elem *one, struct s_elem *two) {
    struct s_stone *tmp = one->start;
    int vtmp;

    one->start = two->start;
    two->start = tmp;

    tmp = one->end;
    one->end = two->end;
    two->end = tmp;

    vtmp = one->val;
    one->val = two->val;
    two->val = vtmp;
}

void sortStones(struct s_stone **stone) {
    if (*stone == NULL)
        return;
    struct s_stone *head = *stone;
    struct s_elem *start = NULL;
    struct s_elem *new;
    while (head != NULL) {
        new = (struct s_elem *)malloc(sizeof(struct s_elem));
        new->start = head;
        new->val = head->size;
        new->next = NULL;
        while (head != NULL && new->val == head->size) {
            new->end = head;
            head = head->next;
        }
        if (start == NULL) {
            start = new;
        }
        else {
            new->next = start;
            start = new;
        }
    }
    struct s_elem *left = start;
    struct s_elem *right = NULL;
    int flag = 0;
    while (left->next != right) {
        if (left->val > left->next->val)
        {
            swap(left, left->next);
            flag = 1;
        }
        left = left->next;
    }
    right = left;
    while (flag) {
        flag = 0;
        left = start;
        while (left->next != right) {
        if (left->val > left->next->val)
        {
            swap(left, left->next);
            flag = 1;
        }
        left = left->next;
        }
        right = left;
    }
    left = start;
    while (left != NULL) {
        left = left->next;
    }
    left = start;
    *stone = start->start;
    while (start->next != NULL) {
        start->end->next = start->next->start;
        start = start->next;
    }
    start->end->next = NULL;
}
