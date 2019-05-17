#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_info {
	int gender;
	int height;
	int hairColor;
	int eyeColor;
	int glasses;
	int tattoo;
	int piercing;
};

struct s_criminal {
	char *name;
	int  description;
};

struct s_node {
	struct s_criminal *crim;
	struct s_node *next;
};

struct s_queue {
  struct s_node *first;
	struct s_node *last;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
int getDescription(struct s_info *info);
void sortCriminals(struct s_criminal **criminals);
struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_criminal **getCriminals(char *filename);
void printCriminals(struct s_criminal **criminals);
struct s_info *getInfo(char *description);

/*--------------------------------
  &  your own other function
  --------------------------------*/
void enqueue(struct s_queue *queue, struct s_criminal *crim);
struct s_criminal *dequeue(struct s_queue *queue);
struct s_queue *queueInit(void);
struct s_criminal *peek(struct s_queue *queue);
int isEmpty(struct s_queue *queue);

#endif
