/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:59:33 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/09 22:59:34 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "header.h"

int getDescription(struct s_info *info) {
    int ret = 0;
    if (info == NULL)
        return ret;
    ret += info->piercing;
    ret += info->tattoo * 10;
    ret += info->glasses * 100;
    ret += info->eyeColor * 1000;
    ret += info->hairColor * 10000;
    ret += info->height * 100000;
    ret += info->gender * 1000000;
    return ret;
}


void sortCriminals(struct s_criminal **criminals) {
    struct s_queue *zero = queueInit();
    struct s_queue *one = queueInit();
    struct s_queue *two = queueInit();
    struct s_queue *three = queueInit();
    struct s_queue *four = queueInit();
    struct s_queue *five = queueInit();
    struct s_queue *six = queueInit();
    struct s_queue *seven = queueInit();
    struct s_queue *eight = queueInit();
    struct s_queue *nine = queueInit();
    char nums[7];
    int i, j, k;
    int val;

    for (i = 0; i < 7; i++) {
        for (j = 0; criminals[j] != NULL; j++) {
            val = criminals[j]->description;
            k = 0;
            for (int l = 0; l < 7; l++)
                nums[l] = '0';
            do {
                int digit = val % 10;
                nums[k] = ('0' + digit);
                val /= 10;
                k++;
            } while (val > 0);
            switch (nums[i]) {
                case '0': enqueue(zero, criminals[j]);
                    break;
                case '1': enqueue(one, criminals[j]);
                    break;
                case '2': enqueue(two, criminals[j]);
                    break;
                case '3': enqueue(three, criminals[j]);
                    break;
                case '4': enqueue(four, criminals[j]);
                    break;
                case '5': enqueue(five, criminals[j]);
                    break;
                case '6': enqueue(six, criminals[j]);
                    break;
                case '7': enqueue(seven, criminals[j]);
                    break;
                case '8': enqueue(eight, criminals[j]);
                    break;
                case '9': enqueue(nine, criminals[j]);
                    break;
                default: printf("Error\n");
            }
        }
        j = 0;
        while (peek(zero) != NULL) {
            criminals[j] = dequeue(zero);
            j++;
        }
        while (peek(one) != NULL) {
            criminals[j] = dequeue(one);
            j++;
        }
        while (peek(two) != NULL) {
            criminals[j] = dequeue(two);
            j++;
        }
        while (peek(three) != NULL) {
            criminals[j] = dequeue(three);
            j++;
        }
        while (peek(four) != NULL) {
            criminals[j] = dequeue(four);
            j++;
        }
        while (peek(five) != NULL) {
            criminals[j] = dequeue(five);
            j++;
        }
        while (peek(six) != NULL) {
            criminals[j] = dequeue(six);
            j++;
        }
        while (peek(seven) != NULL) {
            criminals[j] = dequeue(seven);
            j++;
        }
        while (peek(eight) != NULL) {
            criminals[j] = dequeue(eight);
            j++;
        }
        while (peek(nine) != NULL) {
            criminals[j] = dequeue(nine);
            j++;
        }
    }
    free(zero);
    free(one);
    free(two);
    free(three);
    free(four);
    free(five);
    free(six);
    free(seven);
    free(eight);
    free(nine);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info) {

    int len;
    for (len = 0; criminals[len] != NULL; len++)
        ;
    int count = 0;
    int end;
    int r = len - 1;
    int l = 0;
    int i, k;
    int val = getDescription(info);
    struct s_criminal **ret;
    while (l <= r) {
        i = (l + r) / 2;
        if (criminals[i]->description == val) {
            while (criminals[i]->description == val && i >= 0)
                i--;
            i++;
            for (count = 1, end = i; criminals[end]->description == val; count++, end++)
                ;
            ret = (struct s_criminal **)malloc(sizeof(struct s_criminal*) * (end - i + 2));
            for (k = 0; i < end; i++, k++)
                ret[k] = criminals[i];
            ret[k] = NULL;
            return ret;
        }
        if (criminals[i]->description < val)
            l = i + 1;
        else
            r = i - 1;
    }
    return NULL;
}


struct s_queue *queueInit(void) {
    struct s_queue *new = (struct s_queue *)malloc(sizeof(struct s_queue));
    new->first = NULL;
    new->last = NULL;
    return new;
}

struct s_criminal *dequeue(struct s_queue *queue) {
    struct s_criminal *ret;

    if (queue == NULL)
        return NULL;
    if (queue->first == NULL)
        return NULL;
    struct s_node *elem = queue->first;
    ret = elem->crim;
    queue->first = elem->next;
    free(elem);
    return ret;
}

void enqueue(struct s_queue *queue, struct s_criminal *crim) {
    if (queue == NULL)
        queue = queueInit();
    struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
    new->crim = crim;
    new->next = NULL;
    if (queue->first == NULL) {
        queue->first = new;
        queue->last = new;
    }
    else {
        queue->last->next = new;
        queue->last = new;
    }
}

struct s_criminal *peek(struct s_queue *queue) {
    if (queue == NULL)
        return NULL;
    if (queue->first == NULL)
        return NULL;
    return queue->first->crim;
}

int isEmpty(struct s_queue *queue) {
    if (queue == NULL)
        return 1;
    if (queue->first == NULL)
        return 1;
    return 0;
}