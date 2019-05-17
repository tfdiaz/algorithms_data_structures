/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatWasThat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:31:07 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/07 14:31:10 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define MATCH 0
#define INSERT 1
#define DELETE 2
#define MAXLEN 1000

typedef struct s_cell {
    int cost;
    int parent;
}               t_cell;

t_cell m[MAXLEN + 1][MAXLEN + 1];

void row_init(int i) {
    m[0][i].cost = i;
    if (i > 0)
        m[0][i].parent = INSERT;
    else
        m[0][i].parent = -1;
}

void column_init(int i) {
    m[i][0].cost = i;
    if (i > 0)
        m[i][0].parent = DELETE;
    else
        m[i][0].parent = -1;
}

void goal_cell(char *s, char *t, int *i, int *j) {
    *i = strlen(s) - 1;
    *j = strlen(t) - 1;
}

int match(char c, char d) {
    if (c == d)
        return 0;
    return 1;
}

int indel(char c) {
    return 1;
    (void)c;
}

int string_compare(char *s, char *t) {
    int i, j, k;
    int cost[3];

    for (i = 0; i < MAXLEN; i++) {
        row_init(i);
        column_init(i);
    }

    for (i = 1; (unsigned long)i < strlen(s); i++) {
        for (j = 1; (unsigned long)j < strlen(t); j++) {
            cost[MATCH] = m[i - 1][j - 1].cost + match(s[i],t[j]);
            cost[INSERT] = m[i][j - 1].cost + indel(s[i]);
            cost[DELETE] = m[i-1][j].cost + indel(s[i]);

            m[i][j].cost = cost[MATCH];
            m[i][j].parent = MATCH;
            for (k = INSERT; k <= DELETE; k++) {
                if (cost[k] < m[i][j].cost) {
                    m[i][j].cost = cost[k];
                    m[i][j].parent = k;
                }
            }
        }
    }
    goal_cell(s, t, &i, &j);
    return (m[i][j].cost);
}

char	*whatWasThat(char *word, char **dict) {
    int min_cost = INT_MAX;
    int min_index;
    int cur_cost;

    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < MAXLEN; j++) {
            m[i][j].cost = 0;
            m[i][j].parent = 0;
        }
    }

    for (int i = 0; dict[i] != NULL; i++) {
        cur_cost = string_compare(word, dict[i]);
        if (cur_cost < min_cost) {
            min_cost = cur_cost;
            min_index = i;
        }
    }
    if (min_cost <= DEPTH)
        return (dict[min_index]);
    else
        return NULL;
}

char    *delete(char *word, int pos) {
    int len = strlen(word);
    char *cpy = (char *)malloc(sizeof(char) * len);
    int i = 0;
    while (i < len - 1) {
        if (i == pos)
            word++;
        cpy[i] = *word;
        i++;
        word++;
    }
    cpy[i] = '\0';
    return cpy;
}

char    *replace(char *word, int pos, char c) {
    char *cpy = strdup(word);
    cpy[pos] = c;
    return cpy;
}

char    *add(char *word, int pos, char c) {
    int len = strlen(word);
    char *cpy = (char *)malloc(sizeof(char) * len + 2);
    int i = 0;
    while (i < len + 1) {
        if (i == pos) {
            cpy[i] = c;
            i++;   
        }
        cpy[i] = *word;
        i++;
        word++;
    }
    cpy[i] = '\0';
    return cpy;
}
