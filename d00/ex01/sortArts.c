/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:08:26 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/05 14:08:28 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

static int cmpfunc (const void * a, const void * b) {
   struct s_art **first = (struct s_art**)a;
   struct s_art **second = (struct s_art**)b;
   return strcmp((*first)->name,(*second)->name);
}

void  sortArts(struct s_art **arts) {
    int i = 0;
    while (arts[i] != NULL) {
        i++;
    }
    printf("The number %i\n", i);
    qsort(arts, i, sizeof(struct s_art**), cmpfunc);
    printf("Do I reach here\n");
}

