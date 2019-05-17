/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knightOut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 09:49:29 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/16 09:49:33 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define UR 0
#define RU 1
#define RD 2
#define DR 3
#define DL 4
#define LD 5
#define LU 6
#define UL 7


int getInitialPos(uint64_t board) {
    int ct = -1;
    int flag = 0;
    while (board > 0) {
        ct++;
        if ((board & 1) == 1)
            flag++;
        board = board >> 1;
    }
    return (flag > 1) ? -1: ct;
}

uint64_t make(int i, int j) {
    uint64_t ret = 0;
    if (i >= 0 && j >= 0 && i < 8 && j < 8)
        ret |= (1ULL << (i * 8 + j));
    return ret;
}

uint64_t move(uint64_t board, int type) {
    int i, j;
    int pos = getInitialPos(board);
    i = pos / 8;
    j = pos - i * 8;
    switch (type) {
        case UR :
            i -= 2;
            j += 1;
            break;
        case RU :
            i -= 1;
            j += 2;
            break;
        case RD :
            i += 1;
            j += 2;
            break;
        case DR :
            i += 2;
            j += 1;
            break;
        case DL :
            i += 2;
            j -= 1;
            break;
        case LD :
            i += 1;
            j -= 2;
            break;
        case LU :
            i -= 1;
            j -= 2;
            break;
        case UL :
            i -= 2;
            j -= 1;
            break;
        default :
            printf("Error in switch\n"); 
    }
    return make(i, j);
}

double probs(uint64_t board, int n, double **cache) {
    int cur_pos;
    double p = 0.0;

    if (n == 0 && board > 0)
        return 0;
    if (board == 0)
        return 1;
    cur_pos = getInitialPos(board);
    if (cache[n - 1][cur_pos] > -0.5)
        return cache[n - 1][cur_pos];
    else {
        p += probs(move(board, UR), n - 1, cache) * (double)(1.0 / 8.0);
        p += probs(move(board, RU), n - 1, cache) * (double)(1.0 / 8.0);
        p += probs(move(board, RD), n - 1, cache) * (double)(1.0 / 8.0);
        p += probs(move(board, DR), n - 1, cache) * (double)(1.0 / 8.0);
        p += probs(move(board, DL), n - 1, cache) * (double)(1.0 / 8.0);
        p += probs(move(board, LD), n - 1, cache) * (double)(1.0 / 8.0);
        p += probs(move(board, LU), n - 1, cache) * (double)(1.0 / 8.0);
        p += probs(move(board, UL), n - 1, cache) * (double)(1.0 / 8.0);
        cache[n - 1][cur_pos] = p;
    }
    return cache[n - 1][cur_pos];
}


double knightOut(uint64_t board, int n) {
    double **cache = (double **)malloc(sizeof(double*) * n);
    for (int i = 0; i < n; i++) {
        cache[i] = (double *)malloc(sizeof(double) * 64);
        for (int j = 0; j < 64; j++)
            cache[i][j] = -1.0;
    }
    return probs(board, n, cache);
}
