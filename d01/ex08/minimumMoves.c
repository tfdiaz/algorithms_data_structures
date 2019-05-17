/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimumMoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:24:37 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/08 22:24:40 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "header.h"

size_t hash(void *key) {
	size_t hash = (size_t)key;

    hash ^= (hash >> 7) ^ (hash >> 11) ^ (hash >> 13);
	return hash;
}

struct s_dict *dictInit(int capacity) {
	struct s_dict *new = (struct s_dict *)malloc(sizeof(struct s_dict));
	if (!new)
		return NULL;
	new->capacity = capacity;
	new->items = (struct s_item**)malloc(sizeof(struct s_item*) * capacity);
	if (!new->items)
		return NULL;
	for (int i = 0; i < capacity; i++) {
		new->items[i] = NULL;
	}
	return new;
}

int	dictInsert(struct s_dict *dict, void *key) {
	if (!dict) {
		return 0;
	}
	int index = hash(key) % dict->capacity;
	struct s_item *new = (struct s_item*)malloc(sizeof(struct s_item));
	if (!new) {
		return 0;
	}
	new->key = key;
	new->next = NULL;
	if (dict->items[index] == NULL) {
		dict->items[index] = new;
		return 1;
	}
	else {
		new->next = dict->items[index];
		dict->items[index] = new;
		return 1;
	}
	return 0;
}

int	dictSearch(struct s_dict *dict, void *key) {
	if (!dict) {
		return 0;
	}
	int index = hash(key) % dict->capacity;
	if (dict->items[index] == NULL) {
		return 0;
	}
	else {
		struct s_item *bucket = dict->items[index];
		while (bucket != NULL) {
			if (bucket->key == key) {
				return 1;
			}
			bucket = bucket->next;
		}
	}
	return 0;
}

struct s_queue *queueInit(void) {
    struct s_queue *new = (struct s_queue *)malloc(sizeof(struct s_queue));
    new->first = NULL;
    new->last = NULL;
    return new;
}

void *dequeue(struct s_queue *queue) {
    void *key;

    if (queue == NULL)
        return NULL;
    if (queue->first == NULL)
        return NULL;
    struct s_item *elem = queue->first;
    queue->first = elem->next;
    key = elem->key;
    free(elem);
    return key;
}

void enqueue(struct s_queue *queue, void *key) {
    if (queue == NULL)
        queue = queueInit();
    struct s_item *new = (struct s_item *)malloc(sizeof(struct s_item));
    new->key = key;
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

void *peek(struct s_queue *queue) {
    if (queue == NULL)
        return NULL;
    if (queue->first == NULL)
        return NULL;
    return queue->first->key;
}

int isEmpty(struct s_queue *queue) {
    if (queue == NULL)
        return 1;
    if (queue->first == NULL)
        return 1;
    return 0;
}

void free_queue(struct s_queue **queue) {
    struct s_node *tmp;
    while (!isEmpty(*queue)) {
        tmp = (struct s_node *)dequeue(*queue);
        free (tmp);
    }
    free(*queue);
    *queue = NULL;
}

void free_dict(struct s_dict **dict) {
    free((*dict)->items);
    free(*dict);
    *dict = NULL;
}

int	minimumMoves(struct s_node *begin) {
    struct s_queue *open_set = queueInit();
    struct s_dict *closed_set = dictInit(100);
    struct s_node *tmp;
    struct s_node *empty = (struct s_node *)malloc(sizeof(struct s_node));
    int level = 0;

    enqueue(open_set, (void*)begin);
    enqueue(open_set, empty);
    while (!isEmpty(open_set)) {
        tmp = (struct s_node*)dequeue(open_set);
        if (tmp->isFinal) {
            free_queue(&open_set);
            free_dict(&closed_set);
            return level;
        }
        if (dictSearch(closed_set, tmp) == 0) {
            if (tmp == empty) {
                level++;
                enqueue(open_set, empty);
                if (peek(open_set) == empty)
                    break;
                else
                    continue;
            }
            dictInsert(closed_set, tmp);
            if (tmp->random != NULL) {
                enqueue(open_set, tmp->random);
            }
            if (tmp->next != NULL) {
                enqueue(open_set, tmp->next);
            }
        }
    }
    return -1;
}