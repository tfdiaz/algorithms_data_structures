/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printMST.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:28:15 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/16 12:28:16 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int count(struct s_graph *root) {
    int ct = 0;
    if (root == NULL)
        return ct;
    for (int i = 0; root->nodes[i] != NULL; i++) {
        ct++;
    }
    return ct;
}

void printMST(struct s_graph *graph) {
    int v_ct = count(graph);
    int *parent = (int *)malloc(sizeof(int) * (v_ct + 1));
    unsigned char *intree = (unsigned char *)malloc(sizeof(unsigned char) * v_ct + 1);
    int *distance = (int *)malloc(sizeof(int) * (v_ct + 1));
    int v;
    int next_v;
    int weight;
    int dist;
    struct s_edge **tmp;

    for (int i = 1; i <= v_ct; i++) {
        intree[i] = 0;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[0] = 0;
    v = 0;

    while (intree[v] == 0) {
        intree[v] = 1;
        tmp = graph->nodes[v]->edges;
        for (int i = 0; tmp[i] != NULL; i++) {
            next_v = tmp[i]->dest->id;
            weight = tmp[i]->dist;
            if ((distance[next_v] > weight) && (intree[next_v] == 0)) {
                distance[next_v] = weight;
                parent[next_v] = v;
            }
        }

        v = 1;
        dist = INT_MAX;
        for (int i = 1; i <= v_ct; i++) {
            if ((intree[i] == 0) && (dist > distance[i])) {
                dist = distance[i];
                v = i;
            }
        }
    }
    for (int i = 1; i < v_ct; i++)
        printf("Node: %i to %i\tDistance: %i\n", parent[i], i, distance[i]);
}
