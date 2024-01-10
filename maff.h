#include <stdbool.h>


//! simple vector. it comes with several math operations
struct vector {
  int x;
  int y;
};


struct node;

//! a node meant to be used in a linked list.
struct node {
  //! pointer to next node
  struct node* next;
  //! integer data stored in the node
  int dat;
  //! used internally to tell if a node is free or not
  bool occ;
};

//! creates a map of a linked list for use with llistsortoptimizediterate
struct node **llistsortoptimizedinit(struct node *list, int size);

//! partialy sorts a linked list, must be called multiple times to fully sort list. needs map of linked list to work
void llistsortoptimizediterate(int size, struct node **map);

//! uses several optimizations to quickly sort a linked list
void llistsortoptimized(struct node *list, int size);

//! partialy sorts a linked list, must be called multiple times to fully sort list.
void llistiterate(struct node *list, int size);

//! sorts a linked list
void llistsort(struct node *list, int size);

//! get data from a node in a linked list (indexing starts at zero)
int getnodedat(struct node *list, int id);

//! set data in a node (indexing starts at zero)
void setnodedat(struct node *list, int dat, int id);

//! allocates room on the heap for a linked list
struct node *createlist(int size);

//! returns a pointer to a node in a linked list
struct node *getnodeloc(struct node *list, int id);

//! returns a pointer to the last node in a linked list.
struct node *findlast(struct node *list);

//! finds the first free node in a linked list
struct node *findfree(struct node *list);

//! adds a node to a linked list 
int addnode(struct node *list, int data);

//! prints a linked list
void printlist(struct node *list);

//! removes a node from a linked list (indexing starts at zero)
int removenode(struct node *list, int id);

//! generates a random number between 0 and upperbound
int randomnum(int upperbound);

//! basic addition
int add(int a, int b);

//! basic subtraction
int sub(int a, int b);

//! basic multiplication
int mul(int a, int b);


//! basic division with integers
double divi(int a, int b);

//! calculates area of a square. same logic as in mul()
int areasquare(int b, int h);

//! calculates area of a triangle
int areatriangle(int b, int h);

//! calculates area of a circle
float areacircle(int r);

//! calculates the volume of a rectangular prism.
int volumerectp(int w, int l, int h);

//! calculates the volume of a triangular prism
int volumetrip(int w, int h, int l);

//! adds the values from the source vector to the target vector.
void vadd(struct vector *target, struct vector* source);

//! same as vadd but it uses 2 integers instead of a vector
void vaddi(struct vector *target, int x, int y);

void vsub(struct vector *target, struct vector* source);

void vsubi(struct vector *target, int x, int y);

void vmul(struct vector *target, struct vector* source);

void vmuli(struct vector *target, int x, int y);

//! adds up every value in a list
int sum(int *list, int len);

//! allocates an array before filling it with content
int* setarr(int size, int content);

//! prints an array
void printarr(int *arr, int size);

//! sorts an array
void sort(int *list, int size);

//! returns pi
double pi();
