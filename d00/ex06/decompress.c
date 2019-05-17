/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 21:25:29 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/06 21:25:30 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "header.h"

struct s_string *stringInit(void) {
    struct s_string	*vect;

	vect = (struct s_string*)malloc(sizeof(struct s_string));
	if (!vect)
		return (NULL);
	vect->capacity = 32;
	vect->length = 0;
	vect->content = calloc(32, sizeof(char));
	return (vect);
}

int	stringAppend(struct s_string *s, char *add) {
	char	*new;
	char	*tmp;

	if ((unsigned long)s->capacity < s->length + strlen(add))
	{
		while ((unsigned long)s->capacity < s->length + strlen(add))
			s->capacity *= 2;
		new = (char*)calloc(s->capacity + 1, sizeof(char));
		if (!new)
			return 0;
		tmp = s->content;
		s->content = memmove(new, s->content, s->length);
		if (tmp != NULL)
			free(tmp);
	}
	memcpy(s->content + s->length, add, strlen(add));
	s->length += strlen(add);
	s->content[s->length] = '\0';
	return (1);
}   

char *decompress(char *cBook) {
	struct s_string *ret = stringInit();
	int i, j;
	int ct;
	char **words;
	char *token;
	char elem[2];

	elem[0] = '\0';
	elem[1] = '\0';
	for (ct = 0, i = 0; cBook[i] != '>'; i++) {
		if (cBook[i] == ',')
			ct++;
	}
	char *topline = (char*)malloc(sizeof(char) * i + 1);
	for (j = 0; j < i - 1; j++) {
		topline[j] = cBook[j+1];
	}
	topline[i] = '\0';
	words = (char**)malloc(sizeof(char*) * (ct + 1));
	char look[2] = ",";
	token = strtok(topline, look);
	for (j = 0; token != NULL; j++) {
		words[j] = token;
		token = strtok(NULL, look);
	}
	// printf("%s\n", words[0]);
	cBook = cBook + i + 4;
	while (*cBook) {
		if (*cBook == '@') {
			cBook++;
			unsigned int ind = (unsigned int)*(unsigned char *)cBook;
			stringAppend(ret, words[ind - 1]);
		}
		else {
			elem[0] = *cBook;
			stringAppend(ret, elem);
		}
		cBook++;
	}
	// return "Finished";
	return ret->content;
}
