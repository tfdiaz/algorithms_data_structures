/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 08:27:53 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/17 08:27:54 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

struct s_deque *dequeInit(void) {
    struct s_deque *ret = (struct s_deque*)malloc(sizeof(struct s_deque));
    ret->first = NULL;
    ret->last = NULL;
    return ret;
}

void pushFront(struct s_deque *deque, int value) {
    if (deque == NULL)
        deque = dequeInit();
    struct s_dequeNode *new = (struct s_dequeNode*)malloc(sizeof(struct s_dequeNode));
    new->next = NULL;
    new->prev = NULL;
    new->value = value;
    if (deque->first == NULL) {
        deque->first = new;
        deque->last = new;
    }
    else {
        new->next = deque->first;
        deque->first->prev = new;
        deque->first = new;
    }
}

void pushBack(struct s_deque *deque, int value) {
    if (deque == NULL)
        deque = dequeInit();
    struct s_dequeNode *new = (struct s_dequeNode*)malloc(sizeof(struct s_dequeNode));
    new->next = NULL;
    new->prev = NULL;
    new->value = value;
    if (deque->last == NULL) {
        deque->first = new;
        deque->last = new;
    }
    else {
        new->prev = deque->last;
        deque->last->next = new;
        deque->last = new;
    }       
}

int popFront(struct s_deque *deque) {
    if (deque == NULL)
        return INT_MIN;
    struct s_dequeNode *tmp;
    if (deque->first == NULL)
        return INT_MIN;
    tmp = deque->first;
    deque->first = deque->first->next;
    if (deque->first)
        deque->first->prev = NULL;
    else
        deque->last = NULL;
    return tmp->value;
}

int popBack(struct s_deque *deque) {
    if (deque == NULL)
        return INT_MIN;
    struct s_dequeNode *tmp;
    if (deque->last == NULL)
        return INT_MIN;
    tmp = deque->last;
    deque->last = deque->last->prev;
    if (deque->last)
        deque->last->next = NULL;
    else
        deque->first = NULL;
    return tmp->value;
}

int peekFront(struct s_deque *deque) {
    if (deque == NULL)
        return INT_MIN;
    if (deque->first == NULL)
        return INT_MIN;
    return deque->first->value;
}

int peekBack(struct s_deque *deque) {
    if (deque == NULL)
        return INT_MIN;
    if (deque->last == NULL)
        return INT_MIN;
    return deque->last->value;
}

int isEmpty(struct s_deque *deque) {
    if (deque == NULL)
        return 1;
    if (deque->first == NULL)
        return 1;
    return 0;
}

struct s_max *maxSlidingWindow(int *arr, int n, int k) {
    struct s_max *ret = (struct s_max *)malloc(sizeof(struct s_max));
    ret->length = n;
    ret->max = (int *)calloc(n, sizeof(int));
    struct s_deque *locmax = dequeInit();
    
    if (k < 1) {
        ret->length = 0;
        ret->max[0] = 0;
        return ret;
    }
    if (k > n)
        k = n;
    int i, j;
    for (i = 0; i < k; i++) {
        while (!isEmpty(locmax) && arr[i] >= arr[peekBack(locmax)])
            popBack(locmax);
        pushBack(locmax, i);
    }
    for (j = 0; i < n; i++, j++) {
        ret->max[j] = arr[peekFront(locmax)];
        while (!isEmpty(locmax) && peekFront(locmax) <= i - k)
            popFront(locmax);
        while (!isEmpty(locmax) && arr[i] >= arr[peekBack(locmax)])
            popFront(locmax);
        pushBack(locmax, i);
    }
    ret->length = j + 1;
    ret->max[j] = arr[peekFront(locmax)];
    return ret;
}