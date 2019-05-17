/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:13:13 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/07 20:13:16 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void rever(struct s_node *lst, int ct) {
    if (lst == NULL)
        return;
    rever(lst->next, ct + 1);
    if (ct == 0)
        printf("%s\n", lst->word);
    else
        printf("%s ", lst->word);
    return ;
}

void printReverse(struct s_node *lst) {
    rever(lst, 0);
}