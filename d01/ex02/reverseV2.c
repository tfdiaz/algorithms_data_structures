/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:41:06 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/07 20:41:54 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_stack *stackInit(void) {
    struct s_stack *new = (struct s_stack*)malloc(sizeof(struct s_stack));
    new->item = NULL;
    return new;
}

void *pop(struct s_stack *stack) {
    if (stack == NULL)
        return NULL;
    struct s_item *elem = stack->item;
    stack->item = stack->item->next;
    return (void*)elem;
}

void push(struct s_stack *stack, char *word) {
    struct s_item *new = (struct s_item*)malloc(sizeof(struct s_item));
    new->word = word;
    new->next = NULL;
    if (stack == NULL) {
        stack = stackInit();
        stack->item = new;
        return;
    }
    new->next = stack->item;
    stack->item = new;
}

void printReverseV2(struct s_node *lst) {
    struct s_stack *stack = stackInit();
    struct s_item *item;
    while (lst != NULL) {
        push(stack, lst->word);
        lst = lst->next;
    }
    while (stack->item->next != NULL) {
        item = pop(stack);
        printf("%s ", item->word);
    }
    item = pop(stack);
    printf("%s\n", item->word);
}
