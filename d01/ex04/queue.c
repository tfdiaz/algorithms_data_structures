/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:01:16 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/08 11:01:19 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"
#include <stdlib.h>

struct s_queue *queueInit(void) {
    struct s_queue *new = (struct s_queue *)malloc(sizeof(struct s_queue));
    new->first = NULL;
    new->last = NULL;
    return new;
}

char *dequeue(struct s_queue *queue) {
    char *ret;

    if (queue == NULL)
        return NULL;
    if (queue->first == NULL)
        return NULL;
    struct s_node *elem = queue->first;
    ret = elem->message;
    queue->first = elem->next;
    free(elem);
    return ret;
}

void enqueue(struct s_queue *queue, char *message) {
    if (queue == NULL)
        queue = queueInit();
    struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
    new->message = message;
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

char *peek(struct s_queue *queue) {
    if (queue == NULL)
        return NULL;
    if (queue->first == NULL)
        return NULL;
    return queue->first->message;
}

int isEmpty(struct s_queue *queue) {
    if (queue == NULL)
        return 1;
    if (queue->first == NULL)
        return 1;
    return 0;
}
