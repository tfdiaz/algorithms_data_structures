#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_item {
  char          	*key;
  int				value;
  struct s_item 	*next;
};

struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
};

typedef	struct	s_vect
{
	size_t		cap;
	size_t		ctsize;
	void		*content;
}				t_vect;


/*--------------------------------
  :) function you must implement
  --------------------------------*/

// DICTIONNARY

size_t hash(char *input); //return hash result

struct s_dict *dictInit(int capacity); //initialize the dictionnary, given as parameter the capacity of the array.
int	dictInsert(struct s_dict *dict, char *key, int value); //add one item in the dictionnary, if FAIL return 0, otherwise 1
int	dictSearch(struct s_dict *dict, char *key); //find one element in the dictionnary, if not found, return -1

// OTHER

char *compress(char *book, struct s_dict *dict);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

char *readBookFile(void);
void readWordsFile(char ***pWords, int *pLenWords);

/*--------------------------------
  &  your own other function
  --------------------------------*/

t_vect	*vect_new(void);
t_vect	*vect_add(t_vect *vect, const void *content, size_t content_size);
char	*vect2str(t_vect *vect);


#endif
