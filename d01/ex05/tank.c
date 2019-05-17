/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:16:24 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/08 11:16:26 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

#include <stdio.h>

struct s_tank *initTank(void) {
    struct s_tank *new = (struct s_tank *)malloc(sizeof(struct s_tank));
    new->n = 1;
    new->stacks = (struct s_stack **)malloc(sizeof(struct s_stack*) * 2);
    struct s_stack *stack = (struct s_stack *)malloc(sizeof(struct s_stack));
    stack->elem = NULL;
    stack->sum = 0;
    new->stacks[0] = stack;
    return new;
}

void real(struct s_tank *tank) {
    struct s_stack **newstacks = (struct s_stack**)malloc(sizeof(struct s_stack*) * (tank->n * 2));
    for (int i = 0; i < tank->n; i++) {
        newstacks[i] = tank->stacks[i];
    }
    free(tank->stacks);
    tank->stacks = newstacks;
}

void tankPush(struct s_tank *tank, int energy) {
    if (tank == NULL)
        tank = initTank();
    if (energy < 10 || energy > 101) {
        printf("Too much energy\n");
        return;
    }
    struct s_elem *elem = (struct s_elem *)malloc(sizeof(struct s_elem));
    elem->energy = energy;
    elem->next = NULL;
    if (tank->stacks[0]->elem == NULL) {
        tank->stacks[0]->sum = elem->energy;
        tank->stacks[0]->elem = elem;
        return;
    }
    if (tank->stacks[tank->n - 1]->sum + energy <= 1000) {
        elem->next = tank->stacks[tank->n - 1]->elem;
        tank->stacks[tank->n - 1]->elem = elem;
        tank->stacks[tank->n - 1]->sum += energy;
        return;
    }
    if (tank->stacks[tank->n - 1]->sum + energy > 1000) {
        struct s_stack *stack = (struct s_stack *)malloc(sizeof(struct s_stack));
        stack->sum = elem->energy;
        stack->elem = elem;
        if ((tank->n & (tank->n - 1)) == 0)
            real(tank);
        tank->n++;
        tank->stacks[tank->n - 1] = stack;
    }
}

int tankPop(struct s_tank *tank) {
    int energy;

    if (tank == NULL)
        return 0;
    if (tank->stacks[tank->n - 1]->elem == NULL)
        return 0;
    energy = tank->stacks[tank->n - 1]->elem->energy;
    tank->stacks[tank->n - 1]->sum -= energy;
    tank->stacks[tank->n - 1]->elem = tank->stacks[tank->n - 1]->elem->next;
    if (tank->stacks[tank->n - 1]->elem == NULL) {
        if (tank->n > 1)
            tank->n--;
    }
    return energy;
}