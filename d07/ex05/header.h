#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node {
	char		      c;
	unsigned int	isWord:1;
	struct        s_node	**child;
};

struct s_trie {
	struct s_node *node;
};


char *neverForget(char *words, char **dictionary);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

extern char *g_dict[];

char *get_content(char *file);


/*--------------------------------
  &  your own other function
  --------------------------------*/
struct s_trie *createTrie(char **dictionary);
void insert(struct s_trie *root, char *s);
struct s_node *createNode(char c);
int find(char *word, struct s_node *node);

#endif
