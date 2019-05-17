/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externalSort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:12:01 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/10 11:12:06 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "header.h"

int part(int *arr, int lo, int hi) {
    int i;
    int p;
    int firsthigh;
    int tmp;

    p = hi; 
    firsthigh = lo;
    for (i = lo; i < hi; i++) {
        if (arr[i] < arr[p]) {
            tmp = arr[i];
            arr[i] = arr[firsthigh];
            arr[firsthigh] = tmp;
            firsthigh++;
        }
    }
    tmp = arr[p];
    arr[p] = arr[firsthigh];
    arr[firsthigh] = tmp;
    return (firsthigh);
}

void quick(int *a, int lo, int hi) {
    int p;
    if (lo < hi) {
        p = part(a, lo, hi);
        quick(a, lo, p - 1);
        quick(a, p + 1, hi);
    }
}

char *getName(int ct) {
    char s[20];
    sprintf(s, "%d.tmp", ct);
    return (strdup(s));
}

int reduce(FILE ***block, int ind, int ct) {
    char *name;
    int i;
    for (i = 0; i < 9; i++) {
        if (ind == ct)
            break;
        name = getName(ind);
        (*block)[i] = openFile(name, "r");
        free(name);
        ind++;
    }
    return i;
}

int ctsum(int *ct, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += ct[i];
    return sum;
}

void merge_reduce(FILE *block[], int **load, int place, int len, int ram, int flag, char *end) {
    int index[10];
    int ct[10];
    int min;
    int found;
    char *name;
    if (flag == 0)
        name = getName(place);
    else
        name = end;
    for (int i = 0; i < len; i++) {
        ct[i] = readBlock(block[i], load[i], ram / 10);
    }
    for (int i = 0; i < 10; i++) {
        index[i] = 0;
    }
    while (ctsum(ct, len) > 0) {
        min = INT_MAX;
        for (int j = 0; j < len; j++) {
            if (ct[j] != 0 && load[j][index[j]] < min) {
                found = j;
                min = load[found][index[found]];
            }
        }
        load[9][index[9]] = load[found][index[found]];
        index[9]++;
        index[found]++;
        if (index[9] == ram / 10) {
            appendFile(name, load[9], index[9]);
            index[9] = 0;
        }
        if (index[found] == ct[found]) {
            ct[found] = readBlock(block[found], load[found], ram / 10);
            index[found] = 0;
        }
    }
    if (index[9] > 0)
        appendFile(name, load[9], index[9]);
    if (flag == 0)
        free(name);
}

void deletef(int ct) {
    char *name;
    for (int i = 0; i < ct; i++) {
        name = getName(i);
        if (remove(name) == -1)
            printf("Error on delete %s\n", name);
    }
}

void externalSort(char *scoreFile, char *sortedFile, int ram) {
    ram /= 4;
    int *mem = (int*)malloc(sizeof(int) * ram);
    FILE *fd = openFile(scoreFile, "r");
    int len = 0;
    int ct = 0;
    int added = 0;
    int ind = 0;
    char *name;
    FILE **block = (FILE**)malloc(sizeof(FILE*) * 9);
    while ((len = readBlock(fd, mem, ram)) > 0) {
        quick(mem, 0, len - 1);
        name = getName(ct);
        writeFile(name, mem, len);
        ct++;
    }
    free(mem);
    int **load = (int**)malloc(sizeof(int *) * 10);
    for (int i = 0; i < 10; i++)
        load[i] = (int*)malloc(sizeof(int) * ram / 10);
    added = ct;
    ind = 0;
    while (added > 9) {
        added = 0;
        for (; ind < ct; ind += len) {
            len = reduce(&block, ind, ct);
            added++;
            merge_reduce(block, load, ct + added - 1, len, ram, 0, "");
        }
        ct += added;
    }
    len = reduce(&block, ind, ct);
    merge_reduce(block, load, ct, len, ram, 1, sortedFile);
    for (int i = 0; i < 10; i++)
        free(load[i]);
    free(load);
    deletef(ct);
}