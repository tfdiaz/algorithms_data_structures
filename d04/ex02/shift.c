/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 21:46:48 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/12 21:46:49 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *right(char *s) {
    for (int i = 5; i > 0; i--)
        s[i] = s[i - 1];
    s[0] = '0';
    return s;
}

char *rightneg(char *s) {
    for (int i = 5; i > 0; i--)
        s[i] = s[i - 1];
    s[0] = '1';
    return s;
}

char *left(char *s) {
    for (int i = 0; i < 5; i++)
        s[i] = s[i + 1];
    s[5] = '0';
    s[0] = '0';
    return s;
}

char *leftneg(char *s) {
    for (int i = 0; i < 5; i++)
        s[i] = s[i + 1];
    s[5] = '0';
    s[0] = '1';
    return s;
}

char *rightShift(char *bin, int k) {
    for (int i = 0; i < k; i++) {
        if (bin[0] == '1')
           bin = rightneg(bin);
        else
            bin = right(bin);
    }
    return bin;
}

char *leftShift(char *bin, int k) {
    for (int i = 0; i < k; i++)
        if (bin[0] == '1')
            bin = leftneg(bin);
        else
            bin = left(bin);
    return bin;
}

int toInt(char *bits) {
    int sum = 0;
    int neg = 0;
    int power = 1;
    if (bits[0] == '1')
        neg = 1;
    for (int i = 5; i >= 0; i--) {
        sum += ((bits[i] == '1') ^ neg) * power;
        power *= 2;
    }
    sum += neg;
    if (neg)
        return -sum;
    return sum;
}
