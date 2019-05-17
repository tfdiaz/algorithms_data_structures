/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:56:03 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/17 10:56:04 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct s_tmp {
    char *name;
    int distance;
};

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

struct s_sellers *closestSellers(struct s_graph *graph, char *youAreHere) {
	struct s_queue	*open_set = queueInit();
	struct s_node	*tmp;
	struct s_node	*empty = (struct s_node *)malloc(sizeof(struct s_node));
	int 			level = 0;
    t_vect *vec = vect_new();

    unsigned long i;
    int flag = 0;
    for (i = 0; graph->places[i] != NULL; i++) {
        if (strcmp(graph->places[i]->name, youAreHere) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag) {
	enqueue(open_set, graph->places[i]);
	enqueue(open_set, empty);
	while (open_set->first != NULL) {
		tmp = (struct s_node*)dequeue(open_set);
		if (tmp->hasCerealBar && tmp->visited == 0) {
            struct s_tmp *new = (struct s_tmp*)malloc(sizeof(struct s_tmp));
            new->name = tmp->name;
            new->distance = level;
            vect_add(vec,(void*)&new,sizeof(struct s_tmp*));
        }
		if (tmp->visited == 0) {
			if (tmp == empty) {
				level++;
				enqueue(open_set, empty);
				if (open_set->first->place == (void*)empty)
					break;
				continue;
			}
			tmp->visited = 1;
            for (i = 0; tmp->connectedPlaces[i] != NULL; i++)
			    enqueue(open_set, tmp->connectedPlaces[i]);
		}
	}
	struct s_sellers *ret = (struct s_sellers *)malloc(sizeof(struct s_sellers));
    struct s_tmp *check = *(struct s_tmp**)(vec->content);
    int min = check->distance;
    for (i = 0; i < vec->ctsize / sizeof(struct s_tmp*); i++)
        if ((*((struct s_tmp**)(vec->content + (i * sizeof(struct s_tmp*)))))->distance != min)
            break;
    ret->distance = min;
    ret->placeNames = (char **)calloc(i + 1, sizeof(char *));
    for (i = 0; i < vec->ctsize / sizeof(struct s_tmp*); i++) {
        if ((*((struct s_tmp**)(vec->content + (i * sizeof(struct s_tmp*)))))->distance != min)
            break;
        ret->placeNames[i] = (*((struct s_tmp**)(vec->content + (i * sizeof(struct s_tmp*)))))->name;
    }
    for (int i = 0; graph->places[i] != NULL; i++)
        graph->places[i]->visited = 0;
    return ret;
    }
    return NULL;
}
