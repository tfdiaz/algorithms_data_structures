/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neverForget.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:09:25 by tdiaz             #+#    #+#             */
/*   Updated: 2019/01/17 19:09:26 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int precheck(unsigned char *pre) {
    for (int i = 0; i < 10; i++)
        if (pre[i] == 0)
            return 0;
    return 1;
}

char *neverForget(char *words, char **dictionary) {
    struct s_trie *trie = createTrie(dictionary);
    char **arr = (char **)malloc(sizeof(char*) * 10);
    char **fixed = (char **)malloc(sizeof(char*) * 10);
    char *token = strtok(words, " ");
    for (int i = 0; i < 10; i++) {
        arr[i] = token;
        token = strtok(NULL, " ");
    }
    char shift[27];
    unsigned char pre[7];
    for (int i = 0; i < 27; i++)
        shift[i] = 0;
    for (int i = 0; i < 10; i++)
        pre[i] = 0;
    while (precheck(pre) == 0) {
        for (int i = 0; i < 10; i++) {
            char *tmp = strdup(arr[i]);
            char *tmp2 = strdup(arr[i]);
            for (int j = 0; tmp2[j] != '\0'; j++) {
                if (shift[tmp2[j] - 'a'] != 0)
                    tmp2[j] = shift[tmp2[j] - 'a'];
                else
                    tmp2[j] = '?';
            }
            if (find(tmp2, trie->node)) {
                for (int j = 0; tmp2[j] != '\0'; j++) {
                    shift[tmp[j] - 'a'] = tmp2[j];
                }
                pre[i] = 1;
                fixed[i] = tmp2;
            }
            else {
                pre[i] = 0;
                for (int i = 0; i < 27; i++)
                    shift[i] = 0;
            }
        }
    }
    return fixed[0];
}

struct s_node *createNode(char c) {
    struct s_node *node = (struct s_node *)malloc(sizeof(struct s_node));
    node->c = c;
    node->child = (struct s_node **)calloc(50, sizeof(struct s_node*));
    node->isWord = 0;
    return node;
}

void insert(struct s_trie *root, char *s) {
    struct s_node *node = root->node;
    int index_last = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        index_last = i;
        char c = s[i];
        int flag = 0;
        for (int j = 0; node->child[j] != NULL; j++) {
            if (node->child[j]->c == c) {
                node = node->child[j];
                flag = 1;
                break;
            }
        }
        if (!flag) {
            index_last = i;
            break;
        }
    }
    if (index_last != -1) {
        for (int i = index_last; s[i] != '\0'; i++) {
            int j;
            for (j = 0; node->child[j] != NULL; j++)
                ;
            node->child[j] = createNode(s[i]);
            node = node->child[j];
        }
        node->isWord = 1;
    }
}

struct s_trie *createTrie(char **dictionary) {
    struct s_trie *trie = (struct s_trie*)malloc(sizeof(struct s_trie));
    trie->node = createNode(5);
    for (int i = 0; dictionary[i] != NULL; i++)
        insert(trie, dictionary[i]);
    return trie;
}

int find(char *word, struct s_node *node) {
    if (node == NULL)
        return 0;
    if (*word == '\0') {
        return node->isWord;
    }
    int i = 0;
    int flag = 0;
    if (*word != '?') {
    for (i = 0; node->child[i] != NULL && i < 50; i++) {
        if (node->child[i]->c == *word) {
            flag = 1;
            break;
        }
    }
    if (flag && i < 50)
        return find(word + 1, node->child[i]);
    else
        return 0;
    }
    else {
        int b = 0;
        for (i = 0; node->child[i] != NULL && i < 50; i++) {
            if (node->child[i] && i < 50) {
                *word = node->child[i]->c;
                b = find(word + 1, node->child[i]);
                if (b)
                    return b;
                else
                    *word = '?';
            }
        }
    }
    return 0;
}