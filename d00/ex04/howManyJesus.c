/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:05:58 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/05 17:05:59 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "header.h"


int howManyJesus(char *bible, char *jesus) {
	int len_txt = strlen(bible);
	int len_pat = strlen(jesus);
	int p_hash = 0;
	int t_hash = 0;
	int pw = 1;
	int ct = 0;

	for (int i = 0; i < len_pat - 1; i++) {
		pw = (pw * 256) % 101;
	}

	for (int i = 0; i < len_pat; i++) {
		p_hash = (256 * p_hash + jesus[i]) % 101;
		t_hash = (256 * t_hash + bible[i]) % 101;
	}

	for (int i = 0; i < len_txt - len_pat; i++) {
		if (p_hash == t_hash) {
			if (strncmp(bible + i, jesus, len_pat) == 0)
				ct++;
		}

		if (i < len_txt - len_pat) {
			t_hash = (256 * (t_hash - bible[i] * pw) + bible[i + len_pat]) % 101;
			if (t_hash < 0)
				t_hash = (t_hash + 101);
		}
	}
	return ct;
}
