/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:16:16 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/15 10:16:19 by tdiaz            ###   ########.fr       */
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

void    uts(char *s, int l, int r, struct s_dict *dict) {
	if (l == r && dictSearch(dict, s) == -1) {
		printf("%s\n", s);
		dictInsert(dict, s, 1);
	}
	for (int i = l; i < r; i++) {
		swap(s, i, l);
		uts(s, l + 1, r, dict);
		swap(s, i, l);
	}
}

void	printUniquePermutations(char *str) {
	struct s_dict *dict = dictInit(32);

	if (str != NULL)
		uts(str, 0, strlen(str), dict);
}
