/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxTraffic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:31:07 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/17 14:31:08 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    new->maxT = 0.0;
	new->items = (struct s_item**)malloc(sizeof(struct s_item*) * capacity);
	if (!new->items)
		return NULL;
	for (int i = 0; i < capacity; i++) {
		new->items[i] = NULL;
	}
	return new;
}

void dictFix(struct s_dict *dict, struct s_node *find, float pop) {
    struct s_item *bucket = dictSearch(dict, find);
    struct s_queue *fixlist = queueInit();
    if (bucket == NULL)
        return;
    while (bucket != NULL) {
        if (bucket->start == find) {
            enqueue(fixlist, bucket->end);
            bucket->traffic += pop;
            if (dict->maxT < bucket->traffic)
                dict->maxT = bucket->traffic;
        }
        bucket = bucket->next;
    }
    while (!isEmpty(fixlist)) {
        dictFix(dict, (struct s_node*)dequeue(fixlist), pop);
    }
}

int	dictInsert(struct s_dict *dict, struct s_node *start, struct s_node *end, float pop) {
	if (!dict) {
		return 0;
	}
	int index = hash((void*)start) % dict->capacity;
	struct s_item *new = (struct s_item*)malloc(sizeof(struct s_item));
	if (!new) {
		return 0;
	}
    new->start = start;
    new->end = end;
    new->traffic = pop;
	new->next = NULL;
printf("here before Start %s End %s Pop %f\n", start->name, end->name, pop);
    dictFix(dict, end, pop);
printf("here after\n");
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

struct s_item	*dictSearch(struct s_dict *dict, struct s_node *node) {
	if (!dict) {
		return NULL;
	}
	int index = hash((void*)node) % dict->capacity;
	if (dict->items[index] == NULL)
		return NULL;
	else
		return dict->items[index];
}

int isEmpty(struct s_queue *queue) {
    if (queue == NULL)
        return 1;
    if (queue->first == NULL)
        return 1;
    return 0;
}

float countzero(struct s_node *root) {
    float ret = 0.0;
    for (int i = 0; root->connectedPlaces[i] != NULL; i++) {
        if (root->connectedPlaces[i]->visited == 1)
            ret += 1.0;
    }
    if (ret == 0.0)
        return 1.0;
    return ret;
}

float maxTraffic(struct s_graph *parisPlaces, char *eventHere) {
    int i;
    int index = -1;
    // struct s_dict *dict = dictInit(1000);
    struct s_queue *openset = queueInit();
    struct s_queue *save = queueInit();
    struct s_queue *roots = queueInit();
    struct s_queue *counts = queueInit();
    struct s_queue *dexs = queueInit();
    struct s_node *tmp;
    struct s_node *root;
    int internal = 0;
    int place = 0;
    int count_from_root = 1;
    struct s_node *empty = (struct s_node *)malloc(sizeof(struct s_node));
    empty->visited = 0;
    int *tmp_count;

    for (i = 0; parisPlaces->places[i] != NULL; i++) {
        if (strcmp(eventHere, parisPlaces->places[i]->name) == 0) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        enqueue(openset, (void*)parisPlaces->places[index]);
        enqueue(openset, empty);
        root = parisPlaces->places[index];
        int ct = 0;
        for (ct = 0; root->connectedPlaces[ct] != NULL; ct++)
            ;
        float *arr = (float *)malloc(sizeof(float) * ct);
        int     *ref_ids = (int *)malloc(sizeof(int) * ct);
        for (int j = 0; j < ct; j++) {
            ref_ids[j] = j;
            // enqueue(dexs, ref_ids + j);
            arr[j] = 0.0;
        }
        while (openset->first != NULL && root) {
            tmp = (struct s_node*)dequeue(openset);
            if (tmp == empty) {
                enqueue(openset, empty);
                if ((struct s_node*)openset->first == empty)
                    break;
                while (!isEmpty(save)) {
                    struct s_node *fix = (struct s_node*)dequeue(save);
                    fix->visited = 1;
                }
                for (struct s_queueItem *p = openset->first; p != NULL; p = p->next) {
                    ((struct s_node *)(p->item))->visited = 2;
                }
                continue;
            }
            else {
                enqueue(save, tmp);
                float pop = tmp->population / countzero(tmp);
                if (tmp != root) {
                    place = *(int*)dequeue(dexs);
// printf("Adding %f to place %i node %s\n", pop, place, tmp->name);
                    arr[place] += pop;
                }
                int count = 0;
                for (i = 0; tmp->connectedPlaces[i] != NULL; i++) {
                    if (tmp->connectedPlaces[i]->visited == 0) {
// printf("Adding node %s at place %i\n", tmp->connectedPlaces[i]->name, place);
                        enqueue(openset, tmp->connectedPlaces[i]);
                        if (tmp == root) {
                            enqueue(dexs, ref_ids + i);
                        }
                        else {
                            enqueue(dexs, ref_ids + place);
                        }
                        count++;
                    }
                }
                internal++;
                enqueue(roots, tmp);
                tmp_count = (int *)malloc(sizeof(int));
                *tmp_count = count;
                enqueue(counts, tmp_count);
                if (internal == count_from_root) {
                    root = (struct s_node*)dequeue(roots);
                    count_from_root = *(int *)dequeue(counts);
                    internal = 0;
                }
                while (count_from_root == 0 && root != NULL) {
                    root = (struct s_node*)dequeue(roots);
                    if (root != NULL)
                        count_from_root = *(int *)dequeue(counts);
                }
            }
        }
        float max = -1.0;
        for (int t = 0; t < ct; t++) {
            if (arr[t] > max)
                max = arr[t];
        }
        return max;
    }
    return -1.0;
}