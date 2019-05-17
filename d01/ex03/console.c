/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 21:40:02 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/07 21:40:03 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h"

struct s_stack *initStack(void) {
    struct s_stack *new = (struct s_stack*)malloc(sizeof(struct s_stack));
    new->item = NULL;
    return new;
}

int pop(struct s_stack *stack) {
    if (stack == NULL)
        return -1;
    if (stack->item == NULL)
        return -1;
    struct s_item *elem = stack->item;
    stack->item = stack->item->next;
    return elem->idx;
}

void push(struct s_stack *stack, int idx) {
    struct s_item *new = (struct s_item*)malloc(sizeof(struct s_item));
    new->idx = idx;
    new->next = NULL;
    if (stack == NULL) {
        stack = initStack();
        stack->item = new;
        return;
    }
    new->next = stack->item;
    stack->item = new;
}

char *console(void) {
    char input[260];
    printf("?: ");
    scanf("%260[^\n]", input);
    fseek(stdin,0,SEEK_END);
    return strdup(input);
}