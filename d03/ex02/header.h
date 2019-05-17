#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	char	*name;
	struct s_node **children;
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
struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *getTreeOfLife(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
  