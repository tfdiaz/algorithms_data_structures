/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:45:22 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/12 20:45:25 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

char *negate(char *n) {
    char *ret = (char *)calloc(5, sizeof(char));
    int j = 0;
    for (int i = 0; i < 5; i++) {
        if (n[i] == '~')
            continue;
        if (n[i] == '0')
            ret[j] = '1';
        else
            ret[j] = '0';
        j++;
    }
    return ret;
}

char *getAnd(char *a, char *b) {
    char *ret = (char *)calloc(5, sizeof(char));
    if (strlen(a) == 5)
        a = negate(a);
    if (strlen(b) == 5)
        b = negate(b);
    for (int i = 0; i < 4; i++) {
        if (b[i] == '1' && a[i] == '1')
            ret[i] = '1';
        else
            ret[i] = '0';
    }
    return ret;
}
char *getOr(char *a, char *b) {
    char *ret = (char *)calloc(5, sizeof(char));
    if (strlen(a) == 5)
        a = negate(a);
    if (strlen(b) == 5)
        b = negate(b);
    for (int i = 0; i < 4; i++) {
        if (a[i] == '0' && b[i] == '0')
            ret[i] = '0';
        else
            ret[i] = '1';
    }
    return ret;
}

int toInt(char *bits) {
    int sum = 0;
    for (int i = 3, j = 0; i >= 0; i--, j++) {
        if (bits[i] == '0')
            ;
        else {
            sum += (1 << j);
        }
    }
    return sum;
}