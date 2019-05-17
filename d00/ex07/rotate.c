/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 09:51:41 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/07 09:51:43 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void rotate(int **picture, int n) {
    int index_len = n - 1;

    for (int i = 0; i < n / 2; i++) { 
        for (int j = i; j < index_len - i; j++) { 
            int temp = picture[i][j]; 
            picture[i][j] = picture[index_len - j][i]; 
            picture[index_len - j][i] = picture[index_len - i][index_len - j]; 
            picture[index_len - i][index_len - j] = picture[j][index_len - i]; 
            picture[j][index_len - i] = temp; 
        } 
    } 
}
