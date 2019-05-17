/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:42:58 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/15 09:42:59 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

void swap(char *s, int i, int j) {
	char c;

	c = s[i];
	s[i] = s[j];
	s[j] = c;
}

void    uts(char *s, int l, int r) {
	if (l == r)
		printf("%s\n", s);
	for (int i = l; i < r; i++) {
		swap(s, i, l);
		uts(s, l + 1, r);
		swap(s, i, l);
	}
}

void	printPermutations(char *str) {
	if (str != NULL)
		uts(str, 0, strlen(str));
}
