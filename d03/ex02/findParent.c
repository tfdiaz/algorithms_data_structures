/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:17:24 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/10 21:17:25 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "header.h"

size_t g_first = INT_MAX;

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


void findit(struct s_node *root, char *firstSpecies, char *searchSpecies, t_vect *euler, t_vect *depth, int dep) {
    if (root == NULL)
        return;
    
	vect_add(euler, (void*)root, sizeof(struct s_node*));
	vect_add(depth, (void*)&dep, sizeof(int*));
	for (int i = 0; root->children[i] != NULL; i++) {
		findit(root->children[i], firstSpecies, searchSpecies, euler, depth, dep + 1);
		vect_add(euler, (void*)root, sizeof(struct s_node*));
		vect_add(depth, (void*)&dep, sizeof(int*));
	}
}



struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies) {
    t_vect *euler = vect_new();
    t_vect *depth = vect_new();

	printf("Finding LCA of %s, %s\n", firstSpecies, secondSpecies);
    findit(root, firstSpecies, secondSpecies, euler, depth, 0);

	size_t i = 0;
	int flag = 0;
	size_t dex_len = euler->ctsize / sizeof(struct s_node *);
	char *find;
	struct s_node *ret = NULL;

	for(i = 0; i < dex_len; i++) {
		if (strcmp(((struct s_node*)(euler->content + (i * sizeof(struct s_node*))))->name, firstSpecies) == 0) {
			flag = 1;
			break;
		}
		else if (strcmp(((struct s_node*)(euler->content + (i * sizeof(struct s_node*))))->name, secondSpecies) == 0)
			break;
	}
	if (i == dex_len)
		return NULL;
	size_t end = i;
	find = (flag) ? secondSpecies : firstSpecies;
	while (end < dex_len) {
		if (strcmp(((struct s_node*)(euler->content + (end * sizeof(struct s_node*))))->name, find) == 0)
			break;
		end++;
	}
	if (end == dex_len)
		return NULL;
	int min = INT_MAX;
	int min_dx = 0;
	for (size_t j = i; j < end; j++) {
		if (*(int *)(depth->content + (j * sizeof(int*))) < min) {
			min = *(int *)(depth->content + (j * sizeof(int*)));
			min_dx = j;
		}
	}
	if (i == end)
		min_dx = i;
	ret = (struct s_node*)(euler->content + (min_dx * sizeof(struct s_node*)));
	vect_free(&euler);
	vect_free(&depth);
	return ret;
}