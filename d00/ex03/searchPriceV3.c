/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:39:22 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/05 15:39:26 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

size_t hash(char *input) {
    char c;
    size_t hash = 5381;

    while (*input) {
        c = *input;
        hash = ((hash << 5) + hash) + c;
        input++;
    }
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

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value) {
    if (!dict) {
        return 0;
    }
    int index = hash(key) % dict->capacity;
    struct s_item *new = (struct s_item*)malloc(sizeof(struct s_item));
    if (!new) {
        return 0;
    }
    new->key = key;
    new->value = value;
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

struct s_art *dictSearch(struct s_dict *dict, char *key) {
    if (!dict) {
        return 0;
    }
    int index = hash(key) % dict->capacity;
    if (dict->items[index] == NULL) {
        return NULL;
    }
    else {
        struct s_item *bucket = dict->items[index];
        while (bucket != NULL) {
            if (strcmp(bucket->key, key) == 0) {
                return bucket->value;
            }
            bucket = bucket->next;
        }
    }
    return NULL;
}

int searchPrice(struct s_dict *dict, char *name) {
    struct s_art *found = dictSearch(dict, name);
    if (found == NULL) {
        return -1;
    }
    return found->price;
}
