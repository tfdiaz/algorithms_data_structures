/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 13:33:03 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/05 13:34:40 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "header.h"

int  searchPrice(struct s_art **arts, char *name) {
	while (*arts != NULL) {
		if (strcmp((*arts)->name, name) == 0) {
			return (*arts)->price;
		}
		(arts)++;
	}
	return -1;
}

