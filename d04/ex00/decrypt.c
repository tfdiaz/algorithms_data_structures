/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:37:01 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/12 13:37:02 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

char *getSum(char *a, char *b) {
    int carry = 0;
    for (int i = 5; i >= 0; i--) {
        if (a[i] == '0') {
            if (carry && b[i] == '1') {
                a[i] = '0';
                carry = 1;
            }
            else if (carry && b[i] == '0') {
                a[i] = '1';
                carry = 0;
            }
            else if (b[i] == '1') {
                carry = 0;
                a[i] = '1';
            }
            else {
                a[i] = '0';
                carry = 0;
            }
        }
        else {
            if (b[i] == '1') {
                if (carry) {
                    a[i] = '1';
                }
                else
                    a[i] = '0';
                carry = 1;
            }
            else {
                if (carry) {
                    a[i] = '0';
                    carry = 1;
                }
                else {
                    a[i] = '1';
                    carry = 0;
                }
            }
        }
    }
    return a;
}

int toInt(char *bits) {
    int sum = 0;
    for (int i = 5, j = 0; i >= 0; i--, j++) {
        if (bits[i] == '0')
            ;
        else {
            sum += (1 << j);
        }
    }
    return sum;
}
