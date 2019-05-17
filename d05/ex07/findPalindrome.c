/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPalindrome.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:12:01 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/15 14:12:04 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int help(char *ret, char *tmp, int len) {
	memmove(ret, tmp, len);
	return 1;
}

int uts(char *s, char *ret, int del, int l, int r, int bg, int end, int len) {
	char	*tmp;

	if ((l > r || bg > end) || (s[l] != s[r] && del == 0))
		return (l > r || bg > end);
	if (s[l] != s[r]) {
		tmp = (char *)calloc(len, sizeof(char));
		memmove(tmp, ret, len);
		if (uts(s, tmp, del - 1, l + 1, r, bg, end, len))
			return help(ret, tmp, len);
		memmove(tmp, ret, len);
		if (uts(s, tmp, del - 1, l, r - 1, bg, end, len))
			return help(ret, tmp, len);
		return 0;
	}
	ret[bg] = s[l];
	ret[end] = s[l];
	return uts(s, ret, del, l + 1, r - 1, bg + 1, end - 1, len);
}

char *findPalindrome(char *sequence, int nDelete) {
	char *ret = (char *)calloc(strlen(sequence) - nDelete + 1, sizeof(char));

	if ((int)strlen(sequence) > nDelete) {
		uts(sequence, ret, nDelete, 0, strlen(sequence) - 1, 0, 
			strlen(sequence) - nDelete - 1, strlen(sequence) - nDelete);
		return (strlen(ret) == strlen(sequence) - nDelete) ? ret: NULL;
	}
	return NULL;
}
