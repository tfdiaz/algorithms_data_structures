/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:28:55 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/08 15:28:59 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "header.h"

char *NthLastCity(struct s_city *city, int n) {
    struct s_city *ret = city;
    struct s_city *runner = city;
    while (n >= 0 && runner != NULL) {
        runner = runner->next;
        n--;
    }
    if (runner == NULL && n >= 0)
        return NULL;
    while (runner != NULL) {
        ret = ret->next;
        runner = runner->next;
    }
    return ret->name;
}

// char *NthLastCity(struct s_city *city, int n) {
//     if (city == NULL)
//         return NULL;
//     struct s_city *head = (struct s_city *)malloc(sizeof(struct s_city));
//     head->name = city->name;
//     head->next = NULL;
//     city = city->next;
//     while (city != NULL) {
//         struct s_city *node = (struct s_city *)malloc(sizeof(struct s_city));
//         node->name = city->name;
//         node->next = head;
//         head = node;
//         city = city->next;
//     }
//     for (int i = 0; i < n; i++) {
//         head = head->next;
//     }
//     return head->name;
// }
