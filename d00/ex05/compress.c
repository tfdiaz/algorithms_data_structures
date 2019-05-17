/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:31:38 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/05 19:31:39 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

size_t hash(char *input) {
	char c;
	size_t hash = 5381;

	while (*input) {
		c = *input;
		hash = ((hash << 5) + hash) + c;
		input++;
	}
	return hash;
}

struct s_dict *dictInit(int capacity) {
	struct s_dict *new = (struct s_dict *)malloc(sizeof(struct s_dict));
	if (!new)
		return NULL;
	new->capacity = capacity;
	new->items = (struct s_item**)malloc(sizeof(struct s_item*) * capacity);
	if (!new->items)
		return NULL;
	for (int i = 0; i < capacity; i++) {
		new->items[i] = NULL;
	}
	return new;
}

//add one element in the dictionnary, if FAIL return 0, otherwise 1
int	dictInsert(struct s_dict *dict, char *key, int value) {
	if (!dict) {
		return 0;
	}
	int index = hash(key) % dict->capacity;
	struct s_item *new = (struct s_item*)malloc(sizeof(struct s_item));
	if (!new) {
		return 0;
	}
	new->key = key;
	new->value = value;
	new->next = NULL;
	if (dict->items[index] == NULL) {
		dict->items[index] = new;
		return 1;
	}
	else {
		new->next = dict->items[index];
		dict->items[index] = new;
		return 1;
	}
	return 0;
}

//find one element in the dictionnary, if not found, return NULL
int	dictSearch(struct s_dict *dict, char *key) {
	if (!dict) {
		return 0;
	}
	int index = hash(key) % dict->capacity;
	if (dict->items[index] == NULL) {
		return -1;
	}
	else {
		struct s_item *bucket = dict->items[index];
		while (bucket != NULL) {
			if (strcmp(bucket->key, key) == 0) {
				return bucket->value;
			}
			bucket = bucket->next;
		}
	}
	return -1;
}

char *match(char *text, char *pattern, struct s_dict *dict) {
	unsigned char index[2];
	char alp[2];
	int len_txt = strlen(text);
	int len_pat = strlen(pattern);
	int i;
	t_vect *dyn = vect_new();

	alp[1] = '\0';
	// printf("Len: %i\n", strlen(text));
	for (i = 0; i < len_txt; i++) {
		if (strncmp(text + i, pattern, len_pat) == 0 && i < len_txt - len_pat) {
			index[0] = (unsigned char)(dictSearch(dict, pattern) + 1);
			index[1] = '\0';
			dyn = vect_add(dyn, (void*)"@", sizeof(char));
			dyn = vect_add(dyn, (void*)index, sizeof(char));
			i += len_pat;
		}
		else {
			alp[0] = text[i];
			dyn = vect_add(dyn, (void*)alp, sizeof(char));
		}
	}
	return vect2str(dyn);
}

static int cmpfunc (const void * a, const void * b) {
   struct s_item **first = (struct s_item**)a;
   struct s_item **second = (struct s_item**)b;
   return (*first)->value - (*second)->value;
}

static char *heads(struct s_dict *dict) {
	t_vect *dyn = vect_new();

	if (dict == NULL) {
		return NULL;
	}

	struct s_item **arry = (struct s_item**)malloc(sizeof(struct s_item *) * dict->capacity);
	int index = 0;
	for (int i = 0; i < dict->capacity; i++) {
		if (dict->items[i] == NULL) {
			continue;
		}
		struct s_item *tmp = dict->items[i];
		while (tmp != NULL) {
			arry[index] = tmp;
			tmp = tmp->next;
			index++;
		}
	}
	qsort(arry, dict->capacity, sizeof(struct s_item**), cmpfunc);

	dyn = vect_add(dyn, (void*)"<", sizeof(char));
	for (int i = 0; i < dict->capacity; i++) {
		if (i > 0) {
			dyn = vect_add(dyn, (void*)",", sizeof(char));
		}
		dyn = vect_add(dyn, (void*)arry[i]->key, strlen(arry[i]->key) * sizeof(char));
	}
	dyn = vect_add(dyn, (void*)">", sizeof(char));
	return vect2str(dyn);
}

char *compress(char *book, struct s_dict *dict) {
	char *header;
	char *ret;
	char *cmprss = strdup(book);
	
	header = heads(dict);
	for (int i = 0; i < dict->capacity; i++) {
		if (dict->items[i] == NULL) {
			continue;
		}
		struct s_item *tmp = dict->items[i];
		while (tmp != NULL) {
			// printf("%s\n", cmprss);
			cmprss = match(cmprss, tmp->key, dict);
			tmp = tmp->next;
		}
	}
	ret = (char*)calloc((strlen(header) + strlen(cmprss) + 1), sizeof(char));
	strcpy(ret, header);
	strcat(ret, cmprss);
	return ret;
}

t_vect	*vect_new(void)
{
	t_vect	*vect;

	vect = (t_vect*)malloc(sizeof(t_vect));
	if (!vect)
		return (NULL);
	vect->cap = 32;
	vect->ctsize = 0;
	vect->content = calloc(32, sizeof(char));
	return (vect);
}

t_vect	*vect_add(t_vect *vect, const void *content, size_t content_size)
{
	void	*new;
	void	*tmp;

	if (vect->cap < vect->ctsize + content_size)
	{
		while (vect->cap < vect->ctsize + content_size)
			vect->cap *= 2;
		new = calloc(vect->cap, sizeof(char));
		tmp = vect->content;
		vect->content = memmove(new, vect->content, vect->ctsize);
		if (tmp != NULL)
			free(tmp);
	}
	memcpy(vect->content + vect->ctsize, content, content_size);
	vect->ctsize += content_size;
	return (vect);
}

void	vect_free(t_vect **vect)
{
	if (vect == NULL)
		return ;
	free((*vect)->content);
	free(*vect);
	*vect = NULL;
}

char	*vect2str(t_vect *vect)
{
	char *s;

	if (vect == NULL)
		return (NULL);
	s = (char*)malloc(sizeof(char) * vect->ctsize + 1);
	for (size_t i = 0; i < vect->ctsize; i++) {
		s[i] = *(char*)(vect->content + i);
	}
	s[vect->ctsize] = '\0';
	vect_free(&vect);
	return (s);
}